#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Graph.h"

/* Δημιουργία του γράφου */
Graph *createGraph(int vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
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
}

/* Βοηθητική συνάρτηση για τοπολογική ταξινόμηση */
void topologicalSortUtil(Graph *graph, int v, int visited[], Stack *stack)
{
    visited[v] = 1;
    Edge *adjList = graph->adjLists[v];
    while (adjList != NULL)
    {
        int adjVertex = adjList->dest;
        if (!visited[adjVertex])
            topologicalSortUtil(graph, adjVertex, visited, stack);
        adjList = adjList->next;
    }
    push(stack, v);
}

/* Τοπολογική ταξινόμηση */
void topologicalSort(Graph *graph, Stack *stack)
{
    int *visited = (int *)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++)
        visited[i] = 0;

    for (int i = 0; i < graph->numVertices; i++)
        if (!visited[i])
            topologicalSortUtil(graph, i, visited, stack);

    free(visited);
}

/* Υπολογισμός του συντομότερου μονοπατιού από μία αρχική κορυφή */
void shortestPath(Graph *graph, int startVertex)
{
    Stack *stack = createStack();
    topologicalSort(graph, stack);

    int *dist = (int *)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++)
        dist[i] = INT_MAX;
    dist[startVertex] = 0;

    while (!isEmpty(stack))
    {
        int u = pop(stack);

        if (dist[u] != INT_MAX)
        {
            Edge *adjList = graph->adjLists[u];
            while (adjList != NULL)
            {
                int v = adjList->dest;
                if (dist[u] + adjList->weight < dist[v])
                    dist[v] = dist[u] + adjList->weight;
                adjList = adjList->next;
            }
        }
    }

    for (int i = 0; i < graph->numVertices; i++)
    {
        if (dist[i] == INT_MAX)
            printf("%d: INF\n", i);
        else
            printf("%d: %d\n", i, dist[i]);
    }

    free(dist);
    free(stack);
}

/* Δημιουργία στοίβας */
Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

/* Προσθήκη στοιχείου στη στοίβα */
void push(Stack *stack, int value)
{
    stack->items[++stack->top] = value;
}

/* Αφαίρεση στοιχείου από τη στοίβα */
int pop(Stack *stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->items[stack->top--];
}

/* Έλεγχος αν η στοίβα είναι άδεια */
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}
