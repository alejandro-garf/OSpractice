// Trying to understand input buffer

#include <iostream>

const size_t BUFFER_SIZE = 8192; // Buffer size is referring to how many characters can be held in buffer.
char input[BUFFER_SIZE]; // defining the input array as containing characters whose size is that of the buffer size. 

std::cin.getline(input, BUFFER_SIZE); // readsa the user input line with the sizing limit of buffer size and stores it into the input array