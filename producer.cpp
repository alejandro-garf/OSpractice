// Include headers s stuff works 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>
#include <cstring>
#include <iostream>


int main(){
    const char* name = "/OS";
    const int SIZE = 4096;

    // create the shared memory object
    int shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1){
        std::cerr << "Error creating shared memory\n";
        return 1;
    }


    // Configure its size
    ftruncate(shm_fd, SIZE);

    // Map to memmory 
    void* ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED){
        std::cerr << "Error mapping memory\n";
        return 1;
    }

    // Write Message
    const char* msg = "Hello World";
    strcpy((char*)ptr, msg);

    std::cout << "Producer Wrote: " << msg << std::endl;

    return 0;
}