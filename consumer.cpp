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

    // Open existing shared memory object

    int shm_fd = shm_open(name, O_RDONLY, 0666);
    if (shm_fd == -1){
        std::cerr << "Error creating openining memory\n";
        return 1;
    }
}