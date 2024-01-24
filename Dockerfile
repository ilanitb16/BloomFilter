# Use an official image of a C++ compiler
FROM gcc:latest

# Set the working directory inside the container
WORKDIR /src

# Copy the entire project to the container
COPY . /src/

# Compile the C++ code
RUN g++ -o main Main.cpp BitsArray.cpp HashFunctions.cpp InputOutput.cpp

# Set the entry point for the container
CMD ["./main"]
