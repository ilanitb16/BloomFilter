# Use an official GCC image as the base image
FROM gcc:latest

# Set the working directory inside the container
WORKDIR /src

# Copy the source code to the container
COPY src .

# Compile the C++ files
RUN g++ -o Main Main.cpp BitsArray.cpp InputOutput.cpp HashFunction.cpp

# Set the default command to run the compiled executable
CMD ["./Main"]
