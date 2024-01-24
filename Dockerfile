# Use an official GCC image as the base image
FROM gcc:latest

# Set the working directory inside the container
WORKDIR /app

# Copy the source code to the container
COPY src /app/src

# Compile the C++ files
RUN g++ -o Main Main.cpp /app/src/BitsArray.cpp /app/src/InputOutput.cpp /app/src/HashFunction.cpp

# Set the default command to run the compiled executable
CMD ["./Main"]

