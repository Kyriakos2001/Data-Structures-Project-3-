#ifndef QUEUE_H
#define QUEUE_H

#include "GraphTypes.h"

typedef struct queue
{
    Vertex items[MAXVERTEX];
    int front, rear;
} Queue;

void InitializeQueue(Queue *Q);
int Empty(Queue *Q);
void Insert(Vertex x, Queue *Q);
void Remove(Queue *Q, Vertex *x);

#endif
