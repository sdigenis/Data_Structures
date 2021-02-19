#ifndef __STACK_H_
#define __STACK_H_
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct stack {
    int top;
    unsigned capacity;
    int* array;
}lifo;

lifo *createStack(unsigned capacity);
int isFull(lifo *stack);
int isEmpty(lifo *stack);
void push(lifo *stack, int item);
int pop(lifo *stack);
#endif