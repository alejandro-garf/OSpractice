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
     attr.mq_maxmsg = 10;
     attr.mq_msgsize = 128;
     attr.mq_curmsgs = 0;

     //creating the queue
     mqd_t qid = mq_open(NAME, O_CREAT | O_EXCL | O_RDWR, 0600, &attr);
     if (qid == (mqd_t)-1)
     {
        perror("Creating the queue failed");
        return 1;
     }

     std::cout << "The queue has been created succesfully!\n";

     mq_close(qid);
     if (mq_unlink(NAME) == -1)
     {
        perror("The unlinking has failed");
        return 2;
     }

     std::cout << "The message queue has been deleted!\n";

    return  0;
}