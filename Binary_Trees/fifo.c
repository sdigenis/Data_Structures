#include "fifo.h"
fifo *createQueue(unsigned capacity){ 
    fifo *queue = (fifo*)malloc(sizeof(fifo)); 
    queue->capacity = capacity; 
    queue->front = queue->size = 0;  
    queue->rear = capacity - 1; 
    queue->array = (int*)malloc(queue->capacity * sizeof(int)); 
    return queue; 
}
int fifo_isFull(fifo *queue){ 
    return (queue->size == queue->capacity); 
}
int fifo_isEmpty(fifo *queue){ 
    return (queue->size == 0); 
}
void enqueue(fifo *queue, int item){ 
    if (fifo_isFull(queue)) 
        return; 
    queue->rear = (queue->rear + 1) % queue->capacity; 
    queue->array[queue->rear] = item; 
    queue->size = queue->size + 1; 
    //printf("%d enqueued to queue\n", item); 
}
int dequeue(fifo *queue){ 
    if (fifo_isEmpty(queue)) 
        return INT_MIN; 
    int item = queue->array[queue->front]; 
    queue->front = (queue->front + 1) 
                   % queue->capacity; 
    queue->size = queue->size - 1; 
    return item; 
}
int front(fifo *queue){ 
    if (fifo_isEmpty(queue)) 
        return INT_MIN; 
    return queue->array[queue->front]; 
}
int rear(fifo *queue){ 
    if (fifo_isEmpty(queue)) 
        return INT_MIN; 
    return queue->array[queue->rear]; 
} 