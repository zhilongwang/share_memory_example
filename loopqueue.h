#ifndef __LOOPQUEUE_H_
#define __LOOPQUEUE_H_
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <unistd.h>


using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;
using std::istream;
using std::ofstream;
using std::hex;
#define MYKEY 36
#define QUEUE_LEN 10
// typedef struct Queue{
//     unsigned int read_poi;
//     unsigned int write_poi;
//     unsigned int ini_status;
//     char buffer[QUEUE_LEN];
// }Queue;
class LoopQueue{
    private:
        unsigned int read_poi;
        unsigned int write_poi;
        // 0 represent read_poi == write_poi and write is blocked.
        // 1 represent read_poi == write_poi and read is blocked.
        // 2 none of read_poi and write_poi is blocked.
        unsigned int status; 
        char buffer[QUEUE_LEN];

    public:
        LoopQueue();
        char read_byte();
        bool write_byte(char abyte);
        bool init_queue();


};



#endif