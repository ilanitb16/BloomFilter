FROM gcc:latest
WORKDIR /app

COPY src /app/src

COPY BitsArray /app/src/BitsArray.h
COPY HashFunction /app/src/HashFunction.h
COPY InputOutput /app/src/InputOutput.h

RUN g++ -o Main src/Main.cpp src/BitsArray.cpp src/InputOutput.cpp src/HashFunction.cpp
CMD ["./Main"]
