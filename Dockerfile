FROM gcc:latest
WORKDIR /src
COPY . /src
RUN g++ -o Main Main.cpp BitsArray.cpp
CMD ["./Main"]
