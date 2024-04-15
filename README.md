# Foobar Social Network - Bloom Filter URL Filtering System

A URL filtering system using Bloom filters to protect our users from blacklisted websites. This README will guide you through setting up the project, implementing the Bloom filter in C++ following Test-Driven Development (TDD), and deploying the code to DockerHub.

## Project Setup

Follow these steps to set up the project in a Linux environment:

1. **Create a GitHub Repository**:
   - Create a new private GitHub repository with a README file and .gitignore.

2. **Clone the Repository**:
   - Clone the repository locally to your computer.

3. **Install Required Libraries**:
   - Install required libraries using `sudo apt-get install libgtest-dev cmake`.

To compile the code, we navigated to the src directory where all the classes, including the main, are located, and used the command: g++ Main.cpp.

4. **Build the Project**:
   - Navigate to the src directory and run:
     ```
      cmake --build build
     ```
5. **Run Tests**:
   - Run tests using:
     ```
     ctest --test-dir build --output-on-failure
     ```


## Implementation Details

The code consists of several classes:

### BitsArray Class

The `BitsArray` class represents the bit array used in the Bloom filter. Here's a brief overview of its functionalities:

- **Constructor**: Initializes the size of the array and creates the bit array.
- **addURL**: Adds a URL to the Bloom filter by setting corresponding bits in the array.
- **blackListed**: Checks if a URL is blacklisted by checking corresponding bits in the array.
- **checkFalsePositive**: Checks if a URL is falsely classified as blacklisted.
- **addURLToBitsArray**: Performs hashing on the URL and adds it to the bit array.
- **searchURLInBitArray**: Performs hashing on the URL and checks if it's in the bit array.
- **bloomFilter**: Determines whether to add or search for a URL based on the command number.
- **commandAndURL**: Runs the Bloom filter indefinitely, taking input commands and URLs.

### HashFunctions Class

The `HashFunctions` class provides functionality for hashing URLs. Here's a summary of its features:

- **Constructor**: Parses the input to determine which hash functions to use.
- **getHash1** and **getHash2**: Getters for determining which hash functions are enabled.
- **hash1Function** and **hash2Function**: Implement hash functions on the input URL.
- **mixHashArray**: Combines the results of hashing from multiple functions into one array.

### InputOutput Class

The `InputOutput` class handles input/output operations, such as reading commands and printing messages. Here's what it does:

- **Constructor**: Initializes the class.
- **isDigit**: Checks if a character is a digit.
- **containsNonNumeric**: Checks if the input line contains non-numeric characters.
- **invalidInput**: Checks if the input is invalid and doesn't set the hash functions.
- **firstNum**: Extracts the first number from the input line.
- **setSetting**: Gets the "setting" - the array size and the functions.
- **getCommand**: Gets the input line.
- **printMessage**: Prints true/false messages according to the conditions.

### Main Function

The `main` function initializes instances of the `InputOutput`, `HashFunctions`, and `BitsArray` classes, and runs the Bloom filter based on user input.

This implementation follows Test-Driven Development (TDD) principles, ensuring the integrity and functionality of the Bloom filter. It allows for efficient URL blacklisting and checking, with considerations for false positives and extensibility for multiple hash functions.


## Work division

Initially, we planned how to divide the work. It was decided that Ilanit would work on the first part of STEP1 and handle the tests in STEP2. This was to ensure that the programmer does not write both the tests and the code, so they won't be biased. Additionally, Ilanit was responsible for maintaining and updating the Jira. It was decided that Uri would handle the second part of STEP1 and write the code in STEP2. Uri wrote the appropriate functions and ensured they passed Ilanit's tests. Additionally, Uri performed refactoring. Samuel handled STEP3.

Uri initiated the Jira, and Ilanit filled in the tasks, creating a sprint for each task with the required EPIC for each STEP. She updated the input and output of each test to clarify its purpose, making it easier for Uri to locate any issues. Then she began the sprint and completed the first part of STEP1, including opening the GitHub. Once she finished, Uri began working until we completed STEP1.

Later, Uri and Ilanit sat together to plan how the program would run, what functions were needed, and what the general structure of the code, functions, and MAIN would be. Then, each time Ilanit finished writing a test for a specific function that Uri and Ilanit had planned, Uri took the tests to Visual Studio and wrote the required function there. Once the function ran correctly and fulfilled its role, Uri copied it to VS Code and ran it with the tests. Some functions required minor changes after running the tests, but ultimately everything worked, even after running the tests and verifying that the function worked, we created "helper functions" to make the code more efficient and clearer. For example: input checking functions, the constructor of the HashFunction class, CommandAndURL, which initially was in the MAIN, and a few other functions. In fact, Uri refactored this.

While adding all the tests and functions to VS Code and checking that the code ran smoothly, Samuel approached the task. Initially, we accessed actions and created a new overflow. We trained it for the automatic testing of our tests. Then we created a Docker Hub account, created a repository, and created new token and user secrets. We also created a Dockerfile and a new overflow called docker_image. Lastly, we pushed to the hub. Of course, adjustments were made according to the software and different branches, and after numerous tests and trials, we released a Pre-release.

Finally, we all sat together, showed each other what we had done, worked on the Git to prepare for submission, and submitted.





