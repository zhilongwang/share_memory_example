#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include "loopqueue.h"
// #define BUF_SIZE 1024

 
int main()
{
    int shmid;
    void *shmptr;
 
    if((shmid = shmget(MYKEY, sizeof(LoopQueue), IPC_CREAT | IPC_EXCL | 0666)) == -1)
    {
        perror("shmget error!\n");
        exit(1);
    }
 
    if((shmptr = shmat(shmid, 0, 0)) == (void *)-1)
    {
        perror("shmat error!\n");
        exit(1);
    }
    LoopQueue* queue = (LoopQueue*)shmptr;
    queue->init_queue();
    char input[20];
    while(1)
    {
        printf("input:");
        scanf("%s", input);
        queue->write_byte(input[0]);
    }
 
    exit(0);
}
