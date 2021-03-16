
#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdexcept>

const uint32_t QUEUE_SIZE = 32;

template <typename QueueType>

class Queue {
    
 public:
  Queue(void) {
   data = new QueueType[QUEUE_SIZE];
   capacity= QUEUE_SIZE;
   count=0;
   }
    
 ~Queue(void) {delete[] data;}
    
  int size() { return count; }
    
  bool isEmpty() { return count == 0; }
    
  void clear() {
    count = tail = 0;
    head = QUEUE_SIZE - 1;
  }
    
  void enqueue(QueueType d) {
    if (count == QUEUE_SIZE){
        
       int tmpCap = 2 * capacity;
        
       QueueType *tmpData = new QueueType[tmpCap];
        
    if (tmpData == nullptr)
       throw std::overflow_error("Queue is full");
        
    for (int i=0;i<capacity;i++)
        tmpData[i] = data[(head+i+1)%capacity];
        head=tmpCap-1;
        tail=capacity;
        data[tail] = d;
        tail = (tail + 1) % QUEUE_SIZE;
    count++;
  }
}
  QueueType dequeue() {
    if (count == 0)
      throw std::underflow_error("Queue is empty");
    count--;
    head = ++head % QUEUE_SIZE;    // same as (head+1) % QUEUE_SIZE
    return data[head];
  }
 private:
  QueueType *data;
  int
   count,head,tail,capacity;
};
#endif
