#include <iostream>
#include <unistd.h> //fork , getpid, getppid
#include <sys/types.h> // pid_t


//PID > 0 is the parent process
//PID = 0 is the child process
//PID < 0 is an error

int main()
{
    //Intro message and initalizing fork value
    std::cout << "The garforker is starting...." << std::endl; 

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
        std::cout << "The CHILD PID | " << getpid() << std::endl;
        std::cout << "The PARENT PID | " << getppid() << std::endl;
    } else { // handle for parent
        std::cout << "The Parent PID | " << getpid() << std::endl;
        std::cout << "The CHILD PID | " << pid << std::endl;
    }

    std::cout << "Process " << getpid() << " finshing..." << std::endl;

return 0;
}

