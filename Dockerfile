FROM gcc:latest
WORKDIR /app

COPY src /app/src

RUN g++ -o Main src/Main.cpp src/BitsArray.cpp src/InputOutput.cpp src/HashFunction.cpp
CMD ["./Main"]
