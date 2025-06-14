#ifndef GRAPH_H
#define GRAPH_H

#define MAX_NODES 100

typedef struct Edge
{
    int dest;
    int weight;
    struct Edge *next;
} Edge;

typedef struct Graph
{
    int numVertices;
    Edge *adjLists[MAX_NODES];
} Graph;

typedef struct Stack
{
    int items[MAX_NODES];
    int top;
} Stack;

Graph *createGraph(int vertices);
Edge *createEdge(int dest, int weight);
void addEdge(Graph *graph, int src, int dest, int weight);
void topologicalSortUtil(Graph *graph, int v, int visited[], Stack *stack);
void topologicalSort(Graph *graph, Stack *stack);
void shortestPath(Graph *graph, int startVertex);
Stack *createStack();
void push(Stack *stack, int value);
int pop(Stack *stack);
int isEmpty(Stack *stack);

#endif
