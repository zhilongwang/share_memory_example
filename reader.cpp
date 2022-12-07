#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include "loopqueue.h"
#define BUF_SIZE 1024

 
int  main()
{
    int shmid;
    void * shmptr;
    
    if((shmid = shmget(MYKEY, sizeof(LoopQueue), 0666)) == -1)
    {
        printf("shmget error!\n");
        exit(1);
    }
    if((shmptr = shmat(shmid,0,0)) == (void *)-1)
    {
        printf("shmat error!\n");
        exit(1);
    }
    LoopQueue* queue = (LoopQueue*)shmptr;
    while(1)
    {
        char abyte = queue->read_byte();
        printf("string :%c\n", abyte);
        sleep(1);
    }
 
    exit(0);
}
