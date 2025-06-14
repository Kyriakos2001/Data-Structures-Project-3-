#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "WeightedUndirectedGraph.h"

/* Δημιουργία του γράφου */
Graph *createGraph(int vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

/* Δημιουργία ακμής με βάρος */
Edge *createEdge(int dest, int weight)
{
    Edge *newEdge = (Edge *)malloc(sizeof(Edge));
    newEdge->dest = dest;
    newEdge->weight = weight;
    newEdge->next = NULL;
    return newEdge;
}

/* Προσθήκη ακμής με βάρος */
void addEdge(Graph *graph, int src, int dest, int weight)
{
    Edge *newEdge = createEdge(dest, weight);
    newEdge->next = graph->adjLists[src];
    graph->adjLists[src] = newEdge;

    newEdge = createEdge(src, weight);
    newEdge->next = graph->adjLists[dest];
    graph->adjLists[dest] = newEdge;
}

/* Εκτύπωση του γράφου */
void showGraph(Graph *graph)
{
    for (int v = 0; v < graph->numVertices; v++)
    {
        Edge *temp = graph->adjLists[v];
        printf("\n Vertex %d\n: ", v);
        while (temp)
        {
            printf(" -> %d (weight %d)", temp->dest, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

/* Αρχικοποίηση του γράφου */
void initializeGraph(Graph *graph, int vertices)
{
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
    }
}

/* Ανάγνωση του γράφου από αρχείο */
void readGraphFromFile(Graph *graph, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Error opening file!\n");
        return;
    }

    int vertices, src, dest, weight;
    fscanf(file, "%d", &vertices);
    initializeGraph(graph, vertices);

    while (fscanf(file, "%d-%d-%d", &src, &dest, &weight) != EOF)
    {
        addEdge(graph, src, dest, weight);
    }

    fclose(file);
}

/* Δημιουργία νέου κόμβου MinHeap */
MinHeapNode *newMinHeapNode(int v, int key)
{
    MinHeapNode *minHeapNode = (MinHeapNode *)malloc(sizeof(MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->key = key;
    return minHeapNode;
}

/* Δημιουργία νέου MinHeap */
MinHeap *createMinHeap(int capacity)
{
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->pos = (int *)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode **)malloc(capacity * sizeof(MinHeapNode *));
    return minHeap;
}

/* Εναλλαγή κόμβων MinHeap */
void swapMinHeapNode(MinHeapNode **a, MinHeapNode **b)
{
    MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

/* MinHeapify */
void minHeapify(MinHeap *minHeap, int idx)
{
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->key < minHeap->array[smallest]->key)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->key < minHeap->array[smallest]->key)
        smallest = right;

    if (smallest != idx)
    {
        MinHeapNode *smallestNode = minHeap->array[smallest];
        MinHeapNode *idxNode = minHeap->array[idx];

        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;

        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

        minHeapify(minHeap, smallest);
    }
}

/* Έλεγχος αν το MinHeap είναι άδειο */
int isEmpty(MinHeap *minHeap)
{
    return minHeap->size == 0;
}

/* Εξαγωγή του ελάχιστου στοιχείου από το MinHeap */
MinHeapNode *extractMin(MinHeap *minHeap)
{
    if (isEmpty(minHeap))
        return NULL;

    MinHeapNode *root = minHeap->array[0];

    MinHeapNode *lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;

    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

/* Μείωση του κλειδιού ενός κόμβου στο MinHeap */
void decreaseKey(MinHeap *minHeap, int v, int key)
{
    int i = minHeap->pos[v];

    minHeap->array[i]->key = key;

    while (i && minHeap->array[i]->key < minHeap->array[(i - 1) / 2]->key)
    {
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);

        i = (i - 1) / 2;
    }
}

/* Έλεγχος αν ένας κόμβος βρίσκεται στο MinHeap */
int isInMinHeap(MinHeap *minHeap, int v)
{
    if (minHeap->pos[v] < minHeap->size)
        return 1;
    return 0;
}

/* Εκτύπωση του πίνακα γονέων */
void printArr(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
        printf("%d - %d\n", arr[i], i);
}

/* Υλοποίηση του αλγορίθμου Prim για την εύρεση του ελάχιστου δέντρου κάλυψης */
void primMST(Graph *graph)
{
    int V = graph->numVertices;
    int parent[MAX_NODES];
    int key[MAX_NODES];
    MinHeap *minHeap = createMinHeap(V);

    for (int v = 1; v < V; ++v)
    {
        parent[v] = -1;
        key[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v, key[v]);
        minHeap->pos[v] = v;
    }

    key[0] = 0;
    minHeap->array[0] = newMinHeapNode(0, key[0]);
    minHeap->pos[0] = 0;

    minHeap->size = V;

    while (!isEmpty(minHeap))
    {
        MinHeapNode *minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;

        Edge *pCrawl = graph->adjLists[u];
        while (pCrawl != NULL)
        {
            int v = pCrawl->dest;

            if (isInMinHeap(minHeap, v) && pCrawl->weight < key[v])
            {
                key[v] = pCrawl->weight;
                parent[v] = u;
                decreaseKey(minHeap, v, key[v]);
            }
            pCrawl = pCrawl->next;
        }
    }

    printArr(parent, V);
}
