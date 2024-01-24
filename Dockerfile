FROM gcc:latest
COPY src/Main.cpp /src/Main.cpp
COPY src/BitsArray.cpp /src/BitsArray.cpp
WORKDIR /src
RUN g++ -o Main Main.cpp
CMD ["./Main"]
