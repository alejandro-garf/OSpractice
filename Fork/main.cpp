#include <iostream>
#include <unistd.h> //fork , getpid, getppid
#include <sys/types.h> // pid_t
#include <sys/wait.h> //includes wait 
#include <cstring> // for strcmp

const size_t BUFFER_SIZE = 8192; //buffer size for input arrays

int main()
{

    char input[BUFFER_SIZE]; // initalize input array

    //Intro message 
    std::cout << "Welcome to my Garforker! Produced by Alejandro-garf." << std::endl; 

    // User input handling
    while (true)
    {
        std::cout << "cmd> ";
        std::cin.getline(input, BUFFER_SIZE);

        //Handlinge exit requests
        if (strcmp(input, "exit") == 0)
        {
            std::cout << "Thank you for using my Garforker!" << std::endl;
            break;
        }
    

    std::cout << "You entered: " << input << std::endl;

    pid_t pid = fork();

    // handle for forker fail
    if (pid < 0)
    {
        perror("Sorry you suck and this forking failed, just like your parents marriage.");
        return 1;
    }

    //handle for child 
    if (pid == 0)
    {
        std::cout << "Child: About to run " << input << "...." << std::endl;

        execlp(input, input, (char*)NULL); // replaces the child process with linput executable and terminates
        
        //Erorr handling, should not reach this unless it does not execute input
        perror("command failed and your suck");
        return 1;


    } else { // handle for parent
        std::cout << "Parent: Waiting for child to finish..." << std::endl;

        int status; //box to store the finishing status of the child as an int
        int result = wait(&status); //tells parent to wait until child is done and tells the address of the child process status.
        if(result == -1) {
            perror("something has gone terribly wrong..");
        }
        std::cout << "Child parent " << input << " process has been finished." << std::endl;
    }
    }
    std::cout << "Process " << getpid() << " done..." << std::endl;

return 0;
}