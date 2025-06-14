#include <stdio.h>
#include "WeightedUndirectedGraph.h"

int main()
{
    Graph *graph = createGraph(MAX_NODES);

    readGraphFromFile(graph, "graph.txt");

    printf("Graph:\n");
    showGraph(graph);

    printf("\nMinimum Spanning Tree using Prim's algorithm:\n");
    primMST(graph);

    return 0;
}
