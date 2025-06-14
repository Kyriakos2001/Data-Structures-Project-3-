#include <stdio.h>
#include "Graph.h"

int main()
{
    int vertices = 6;
    Graph *graph = createGraph(vertices);

    addEdge(graph, 0, 1, 5);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 1, 3, 6);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 2, 4, 4);
    addEdge(graph, 2, 5, 2);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 3, 4, -1);
    addEdge(graph, 4, 5, -2);

    int startVertex = 1;
    printf("Shortest paths from vertex %d:\n", startVertex);
    shortestPath(graph, startVertex);

    return 0;
}
