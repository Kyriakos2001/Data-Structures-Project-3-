#include <stdio.h>
#include "Queue.h"

/* Αρχικοποίηση ουράς */
void InitializeQueue(Queue *Q)
{
    Q->front = 0;
    Q->rear = -1;
}

/* Έλεγχος αν η ουρά είναι άδεια */
int Empty(Queue *Q)
{
    return Q->rear < Q->front;
}

/* Εισαγωγή στοιχείου στην ουρά */
void Insert(Vertex x, Queue *Q)
{
    if (Q->rear < MAXVERTEX - 1)
    {
        Q->items[++Q->rear] = x;
    }
    else
    {
        printf("Queue is full\n");
    }
}

/* Αφαίρεση στοιχείου από την ουρά */
void Remove(Queue *Q, Vertex *x)
{
    if (!Empty(Q))
    {
        *x = Q->items[Q->front++];
    }
    else
    {
        printf("Queue is empty\n");
    }
}
