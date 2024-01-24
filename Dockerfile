FROM gcc:latest
WORKDIR /app

COPY src /app/src
COPY InputOutput src/InputOutput.h
COPY HashFunction src/HashFunction.h
COPY BitsArray src/BitsArray.h

RUN g++ -o Main src/Main.cpp src/BitsArray.cpp src/InputOutput.cpp src/HashFunction.cpp
CMD ["./Main"]
