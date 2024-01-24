# Use an official GCC image as the base image
FROM gcc:latest

# Copy the source code to the container
COPY src /src

# Compile the C++ files
RUN g++ -o Main Main.cpp src/BitsArray.cpp src/InputOutput.cpp src/HashFunction.cpp

# Set the default command to run the compiled executable
CMD ["./Main"]

