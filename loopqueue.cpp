
#include "loopqueue.h"
LoopQueue::LoopQueue(){
    this->status = 1;
}
char LoopQueue::read_byte(){
    while(this->write_poi == this->read_poi && this->status == 1){
        cout << "read blocked" << endl;
        sleep(1);
    }
    if (this->write_poi == this->read_poi + 1){
        this->status = 1;
    }
    char one_byte = this->buffer[this->read_poi];
    this->read_poi = (this->read_poi + 1) % QUEUE_LEN ;

    return one_byte;
}
        
bool LoopQueue::write_byte(char abyte){
    while(this->write_poi == this->read_poi &&  this->status == 0){
        cout << "write blocked" << endl;
        sleep(1);
    }
    if (this->write_poi == this->read_poi){
        this->status = 0;
    }
    this->buffer[this->write_poi] = abyte;
    this->write_poi = (this->write_poi + 1) % QUEUE_LEN;
    return true;
}

bool LoopQueue::init_queue(){
    this->status = 1;
    this->write_poi = 0;
    this->read_poi = 0;
}
