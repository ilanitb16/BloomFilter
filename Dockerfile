FROM gcc:latest
COPY test_main.cpp  /tests/test_main.cpp 
RUN g++ -o test_main test_main.cpp 
CMD ["./test_main"]
