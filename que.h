//Queue accessories...

#include<stdlib.h>
#include<stdio.h>
struct Queue
{
    int front,rear;
    int capacity;
    int* array;
    int size;
};
struct Queue* create_queue(int);
void enque(struct Queue*,int);
int Queue_full(struct Queue*);
int Queue_empty(struct Queue*);
int deque(struct Queue*);

