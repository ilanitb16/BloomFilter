#include <vector>
#include "BitsArray.h"
#include "HashFunctions.h"
#include "InputOutput.h"
#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <thread>

using namespace std;

std::string cutUrl(const char* buffer) {
    // Find the position of the first occurrence of ".com" in the buffer
    const char* com_pos = strstr(buffer, ".com");
    if (com_pos != nullptr) {
        // Calculate the length of the URL, including ".com"
        size_t url_len = com_pos - buffer + 4; // Include the length of ".com"
        // Extract the URL from the buffer
        return std::string(buffer, url_len);
    } else {
        return ""; // ".com" not found in the buffer
    }
}

bool isSet = false;
HashFunctions hashFunctions("1 1");
BitsArray bitsArray(0);
InputOutput inputOutput;

void handleConnection(int client_sock) {
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes;

    while ((read_bytes = recv(client_sock, buffer, expected_data_len, 0)) > 0) {
        cout << "connection working: " << buffer << endl;

        //if the bit array isn't set
        if (isSet) {
            string numAndUrl = cutUrl(buffer);
            cout << "number and url: " << numAndUrl << endl;
            bool bloomFilterResult = bitsArray.commandAndURL(inputOutput, hashFunctions, numAndUrl);
            if (bloomFilterResult) {
                buffer[0] = 1;
            } else {
                buffer[0] = 0;
            }
        } else {
            isSet = true;
            string setting = buffer;
            int arraySize = inputOutput.firstNum(setting);
            HashFunctions newHashFunctions(setting);
            hashFunctions = newHashFunctions;
            BitsArray empty(arraySize);
            bitsArray = empty;
        }

        int sent_bytes = send(client_sock, buffer, read_bytes, 0);
        if (sent_bytes < 0) {
            perror("error sending to client");
            return;
        }
    }

    if (read_bytes == 0) {
        // Connection closed by client
    } else {
        perror("error receiving from client");
    }

    close(client_sock);
}

int main() {
    const int server_port = 7979;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
        return 1;
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    if (bind(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
        perror("error binding socket");
        return 1;
    }

    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
        return 1;
    }

    while (true) {
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *)&client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
            return 1;
        }

        thread t(handleConnection, client_sock);
        t.detach();
    }

    close(sock);
    return 0;
}
