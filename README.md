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

4. Install g++ compiler and other required dependencies:

To compile the code, we navigated to the src directory where all the classes, including the main, are located, and used the command: g++ Main.cpp BitsArray.cpp InputOutput.cpp HashFunctions.cpp -o server
then write ./server

Other links: 
- https://github.com/ilanitb16/facebook-ex2.git
- https://github.com/ShmuelGranot/Facebook-iso-APP
