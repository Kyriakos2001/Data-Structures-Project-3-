#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

void findShortestPath(int sets[][MAX_NODES], int setSizes[], int numSets, int weights[MAX_NODES][MAX_NODES]);

int main()
{
    int sets[3][MAX_NODES] = {{0, 1}, {2, 3}, {4}};
    int setSizes[3] = {2, 2, 1};
    int numSets = 3;

    int weights[MAX_NODES][MAX_NODES] = {
        {0, 10, 15, 20, 10},
        {10, 0, 35, 25, 20},
        {15, 35, 0, 30, 30},
        {20, 25, 30, 0, 10},
        {10, 20, 30, 10, 0}};

    findShortestPath(sets, setSizes, numSets, weights);

    return 0;
}

void findShortestPath(int sets[][MAX_NODES], int setSizes[], int numSets, int weights[MAX_NODES][MAX_NODES])
{
    int newVertexCount = 0;
    for (int i = 0; i < numSets; i++)
        newVertexCount += setSizes[i];

    Graph *newGraph = createGraph(newVertexCount);

    int vertexOffset[MAX_NODES];
    vertexOffset[0] = 0;
    for (int i = 1; i < numSets; i++)
        vertexOffset[i] = vertexOffset[i - 1] + setSizes[i - 1];

    for (int i = 0; i < numSets - 1; i++)
    {
        for (int uIndex = 0; uIndex < setSizes[i]; uIndex++)
        {
            int u = sets[i][uIndex];
            for (int vIndex = 0; vIndex < setSizes[i + 1]; vIndex++)
            {
                int v = sets[i + 1][vIndex];
                addEdge(newGraph, vertexOffset[i] + uIndex, vertexOffset[i + 1] + vIndex, weights[u][v]);
            }
        }
    }

    printf("Shortest paths in the transformed graph:\n");
    shortestPath(newGraph, 0);

    for (int i = 0; i < newGraph->numVertices; i++)
    {
        Edge *edge = newGraph->adjLists[i];
        while (edge)
        {
            Edge *temp = edge;
            edge = edge->next;
            free(temp);
        }
    }
    free(newGraph);
}
