#include <iostream>

int main() 
{
    char buffer[8192];

    std::cout << "Enter your prompt" << std::endl;
    std::cout << "==> ";

    std::cin.getline(buffer, 8192);

    std::cout << "You entered: " << buffer << std::endl;

    return 0;
}