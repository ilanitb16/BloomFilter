FROM gcc:latest
COPY src/Main.cpp /src/Main.cpp
WORKDIR /src
RUN g++ -o Main Main.cpp
CMD ["./Main"]
