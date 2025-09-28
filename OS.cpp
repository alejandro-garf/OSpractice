// Include headers s stuff works 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>


#define BUFFER_SIZE 10

typedef struct 
{
    int buffer[BUFFER_SIZE];
    int in;
    int out;
} shared_data;

int main()
{
    int fd = shm_open("/my_shm", O_CREAT | O_RDWR, 0666);
    ftruncate(fd, sizeof(shared_data));
    shared_data *data = (shared_data*) mmap(0, sizeof(shared_data),
                          PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    

}
