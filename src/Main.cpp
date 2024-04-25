#include <vector>
#include "BitsArray.h"
#include "HashFunctions.h"
#include "InputOutput.h"
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

/*
int main()
{
    InputOutput inputOutput;
    std::string setting = inputOutput.setSetting();
    int arraySize = inputOutput.firstNum(setting);
    HashFunctions hashFunctions(setting);
    BitsArray bitsArray(arraySize);   

    bitsArray.commandAndURL(inputOutput, hashFunctions);
}
*/


using namespace std;

bool isSet = false;
HashFunctions hashFunctions;
BitsArray bitsArray;
InputOutput inputOutput;

int main() {
    const int server_port = 5555;
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

    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    int client_sock = accept(sock, (struct sockaddr *)&client_sin, &addr_len);
    if (client_sock < 0) {
        perror("error accepting client");
        return 1;
    }

    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        // connection is closed
    } else if (read_bytes < 0) {
        // error
    } else {
        //if the bit array isn't set
        if (isSet) {
            bool bloomFilterResult = bitsArray.commandAndURL(inputOutput, hashFunctions, buffer);
            if(bloomFilterResult) {
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
    }
    
    int sent_bytes = send(client_sock, buffer, read_bytes, 0);
    if (sent_bytes < 0) {
        perror("error sending to client");
        return 1;
    }

    close(sock);
    return 0;
}