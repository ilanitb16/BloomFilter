FROM gcc:latest
WORKDIR /app

# Copy source files
COPY src /app/src

# Compile the C++ files
RUN g++ -o Main /app/src/Main.cpp /app/src/BitsArray.cpp /app/src/InputOutput.cpp /app/src/HashFunction.cpp

# Set the default command to run the compiled executable
CMD ["./Main"]
