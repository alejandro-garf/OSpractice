#include <iostream>
#include <fcntl.h>    
#include <sys/mman.h> 
#include <unistd.h>   
#include <cstdlib>


int main()
{
    const char* name = "/garfinator";
    const int SIZE = 1024;

    int fd = shm_open(name, O_CREAT | O_EXCL | O_RDWR, 0600);
    if (fd == -1)
    {
        perror("shm_open failed");
        exit(1);
    }

    std::cout << "Memory object has been created succesfully!" << std::endl;

    if (ftruncate(fd, SIZE) == -1)
    {
        perror("ftruncate error");
        exit(1);
    }

    std::cout << "Size has been set" << std::endl;

    close(fd);
    shm_unlink(name);

    std::cout << "Shared memory object has been deleted!" << std::endl;


    return 0;
}