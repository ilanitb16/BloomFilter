# Use an official GCC image as the base image
FROM gcc:latest

# Copy the source code to the container
COPY Main ./src/Main.cpp
COPY BitsArray ./src/BitsArray.cpp
COPY InputOutput ./src/InputOutput.cpp
COPY HashFunction ./src/HashFunction.cpp
COPY BitsArray ./src/BitsArray.h
COPY InputOutput ./src/InputOutput.h
COPY HashFunction ./src/HashFunction.h
# Compile the C++ files
RUN g++ -o Main ./src/Main.cpp ./src/BitsArray.cpp ./src/InputOutput.cpp ./src/HashFunction.cpp

# Set the default command to run the compiled executable
CMD ["./Main"]
