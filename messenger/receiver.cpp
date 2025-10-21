#include <iostream>
#include <mqueue.h>
#include <fcntl.h>     
#include <sys/stat.h>
#include <cstring>
#include <unistd.h>


int main ()
{
    const char* NAME = "/garfqueue"; // name 

    //Opening existinf queue
    mqd_t qid = mq_open(NAME, O_RDONLY);
     if (qid == (mqd_t)-1)
     {
        perror("Creating the queue failed");
        return 1;
     }

     //buffer that will be storing the incoming message
     char buffer[128];

     //receiving the message 
     ssize_t pompom = mq_receive(qid, buffer, sizeof(buffer), nullptr);
     if (pompom == -1)
     {
        perror("The message was not received");
        mq_close(qid);
        return 2;
     }
     
    std::cout << "The message has been received = " << buffer << std::endl;
    mq_close(qid);
    mq_unlink(NAME);

    std::cout << "Everything has been reset\n";

    return 0;
}