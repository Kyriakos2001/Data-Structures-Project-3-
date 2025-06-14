#ifndef WEIGHTEDUNDIRECTEDGRAPH_H
#define WEIGHTEDUNDIRECTEDGRAPH_H

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

typedef struct MinHeapNode
{
    int v;
    int key;
} MinHeapNode;

typedef struct MinHeap
{
    int size;
    int capacity;
    int *pos;
    MinHeapNode **array;
} MinHeap;

Graph *createGraph(int vertices);
Edge *createEdge(int dest, int weight);
void addEdge(Graph *graph, int src, int dest, int weight);
void showGraph(Graph *graph);
void initializeGraph(Graph *graph, int vertices);
void readGraphFromFile(Graph *graph, const char *filename);

MinHeapNode *newMinHeapNode(int v, int key);
MinHeap *createMinHeap(int capacity);
void swapMinHeapNode(MinHeapNode **a, MinHeapNode **b);
void minHeapify(MinHeap *minHeap, int idx);
int isEmpty(MinHeap *minHeap);
MinHeapNode *extractMin(MinHeap *minHeap);
void decreaseKey(MinHeap *minHeap, int v, int key);
int isInMinHeap(MinHeap *minHeap, int v);
void printArr(int arr[], int n);
void primMST(Graph *graph);

#endif
