#include <stdio.h>
#include "GraphTypes.h"

int main()
{
    Graph G;
    int numVertices, u, v;
    char filename[100];

    printf("Enter the filename containing the graph: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    fscanf(file, "%d", &numVertices);
    Initialize(&G, numVertices);

    while (fscanf(file, "%d-%d", &u, &v) != EOF)
    {
        InsertEdge(&G, u, v);
    }
    fclose(file);

    printf("Original Graph:\n");
    ShowGraph(G);

    printf("\nDepth-First Search:\n");
    DepthFirst(G, PrintElement);
    printf("\n");

    printf("\nTopological Sort:\n");
    Vertex T[MAXVERTEX];
    BreadthTopSort(G, T);
    for (int i = 0; i < G.n; i++)
    {
        printf("%d ", T[i]);
    }
    printf("\n");

    printf("\nGraph Reverse:\n");
    Graph R = GraphReverse(G);
    ShowGraph(R);

    printf("\nStrongly Connected Components:\n");
    int sc[MAXVERTEX];
    Kosaraju(G, sc);
    for (int i = 0; i < G.n; i++)
    {
        printf("Vertex %d is in component %d\n", i, sc[i]);
    }

    return 0;
}
