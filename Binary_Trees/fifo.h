#ifndef __FIFO_H_
#define __FIFO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define SIZE 1000

typedef struct fifo { 
    int front, rear, size; 
    unsigned capacity; 
    int* array; 
}fifo;

fifo *createQueue(unsigned capacity);
int fifo_isFull(fifo *queue);
int fifo_isEmpty(fifo *queue);
void enqueue(fifo *queue, int item);
int dequeue(fifo *queue);
int front(fifo *queue);
int rear(fifo *queue);
#endif