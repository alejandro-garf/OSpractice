#include <iostream>
#include <mqueue.h>     // mq_* functions
#include <fcntl.h>      // O_CREAT, O_RDWR
#include <sys/stat.h>   // permission bits
#include <cstring>      // strerror
#include <cerrno>

int main()
{
     const char* NAME = "/garfqueue";

     struct mq_attr attr;
     attr.mq_flags = 0;
     attr.mq_mxmsg = 10;
     attr.mq_msgsize = 128;
     attr.mq_curmsg = 0;



    return  0;
}