#include <iostream>
#include <mqueue.h>     // mq_* functions
#include <fcntl.h>      // O_CREAT, O_RDWR
#include <sys/stat.h>   // permission bits
#include <cstring>      // strerror
#include <cerrno>

int main()
{
    const char* NAME = "/garfqueue"; // name 

    //attributes
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 128;
    attr.mq_curmsgs = 0;  

    //Opening the sender queue
    mqd_t qid = mq_open(NAME, O_CREAT | O_WRONLY, 0600, &attr);
     if (qid == (mqd_t)-1)
     {
        perror("Creating the queue failed");
        return 1;
     }

     //message to be sent
     const char* messege = "Hey there my friend";

     //sending the message

     if(mq_send(qid, messege, strlen(messege) + 1, 0) ==  -1)
     {
        perror("The message has failed to send.");
        mq_close(qid);
        return 2;
    }

    std::cout << "The message has been sent!\n";
    mq_close(qid);


    return 0;
}