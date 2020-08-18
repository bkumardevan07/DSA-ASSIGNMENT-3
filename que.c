#include<stdio.h>
#include<stdlib.h>
#include"header.h"
#include"que.h"

int Queue_full(struct Queue* q)
{
    return (q->size == q->capacity);    
}

int Queue_empty(struct Queue* q)
{
    return (q->size==0);
}
struct Queue* create_queue(int no_of_vertices)
{
    struct Queue* q;
    q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = no_of_vertices+1;
    q->array = (int*)malloc(q->capacity*sizeof(int));
    q->front = 0;
    q->size = 0;
    q->rear = q->capacity-1;
    return q;
}

void enque(struct Queue* q,int k)
{
    if (Queue_full(q))
    {
        printf("\nQueue Full. Exiting...\n");
        exit(0);
    }
    q->rear = (q->rear+1)%(q->capacity);
    q->array[q->rear] = k; 
    q->size++;
}

int deque(struct Queue* q)
{
    int v;
    if(Queue_empty(q))
    {
        printf("\nQueue Empty. Exiting...\n");
        exit(0);
    }
    v = q->array[q->front];
    q->front = (q->front+1)%(q->capacity);
    q->size--;
    return v;
}