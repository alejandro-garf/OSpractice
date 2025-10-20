#include <iostream>
#include <unistd.h> //fork , getpid, getppid
#include <sys/types.h> // pid_t
#include <sys/wait.h> //includes wait 


//PID > 0 is the parent process
//PID = 0 is the child process
//PID < 0 is an error

int main()
{
    //Intro message and initalizing fork value
    std::cout << "The garforker is starting and will exexute ls...." << std::endl; 

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
        std::cout << "Child: About to run ls....." << std::endl;

        execlp("ls", "ls", (char*)NULL); // replaces the child process with ls executable and terminates
        
        //Erorr handling, should not reach this unless it does not execute ls
        perror("Ls failed and your suck");
        return 1;


    } else { // handle for parent
        std::cout << "Parent: Waiting for child to finish..." << std::endl;

        int status; //box to store the finishing status of the child as an int
        int result = wait(&status); //tells parent to wait until child is done and tells the address of the child process status.
        if(result == -1) {
            perror("something has gone terribly wrong..");
        }
        std::cout << "Child parent ls process has been finished." << std::endl;
    }

    std::cout << "Process " << getpid() << " done..." << std::endl;

return 0;
}