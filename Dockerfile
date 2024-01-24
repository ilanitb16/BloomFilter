# Use an official GCC image as the base image
FROM gcc:latest

# Set the working directory in the container
WORKDIR /src

# Copy the source code to the container
COPY Main.cpp BitsArray.cpp InputOutput.cpp HashFunctions.cpp ./src/
COPY BitsArray.h InputOutput.h HashFunctions.h ./src/

# Compile the C++ files
RUN g++ -o Main Main.cpp BitsArray.cpp InputOutput.cpp HashFunctions.cpp

# Set the default command to run the compiled executable
CMD ["./Main"]
