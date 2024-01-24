FROM gcc:latest
COPY Main.cpp  /src/Main.cpp
RUN g++ -o Main Main.cpp 
CMD ["./Main"]
