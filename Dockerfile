FROM gcc:latest

COPY ./src/Main.cpp ./src/
COPY ./src/BitsArray.cpp ./src/
COPY ./src/InputOutput.cpp ./src/
COPY ./src/HashFunctions.cpp ./src/
COPY ./src/BitsArray.h ./src/
COPY ./src/InputOutput.h ./src/
COPY ./src/HashFunctions.h ./src/

RUN g++ -o Main ./src/Main.cpp ./src/BitsArray.cpp ./src/InputOutput.cpp ./src/HashFunctions.cpp

CMD ["./Main"]
