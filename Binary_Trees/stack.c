#include "stack.h"
lifo *createStack(unsigned capacity){
    lifo *stack = (lifo *)malloc(sizeof(lifo));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(lifo *stack){
    return stack->top == stack->capacity - 1;
}

int isEmpty(lifo *stack){
    return stack->top == -1;
}

void push(lifo *stack, int item){
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    //printf("%d pushed to stack\n", item);
}

int pop(lifo *stack){
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}