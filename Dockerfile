# Use an official GCC image as the base image
FROM gcc:latest

# Set the working directory in the container
WORKDIR /src

# Copy the source code to the container
COPY ./src/Main.cpp ./src/
COPY ./src/BitsArray.cpp ./src/
COPY ./src/InputOutput.cpp ./src/
COPY ./src/HashFunctions.cpp ./src/
COPY ./src/BitsArray.h ./src/
COPY ./src/InputOutput.h ./src/
COPY ./src/HashFunctions.h ./src/

# Compile the C++ files
RUN g++ -o ./src/Main ./src/Main.cpp ./src/BitsArray.cpp ./src/InputOutput.cpp ./src/HashFunctions.cpp

# Set the default command to run the compiled executable
CMD ["./src/Main"]
