# Use an official GCC image as the base image
FROM gcc:latest

# Copy the source code to the container
COPY ./src/Main ./src/Main.cpp
COPY ./src/BitsArray ./src/BitsArray.h
COPY ./src/InputOutput ./src/InputOutput.h
COPY ./src/HashFunction ./src/HashFunction.h
# Compile the C++ files
RUN g++ -o Main ./src/Main.cpp ./src/BitsArray.cpp ./src/InputOutput.cpp ./src/HashFunction.cpp

# Set the default command to run the compiled executable
CMD ["./Main"]
