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

    Vertex start, end;
    printf("\nEnter two vertices to check for a simple path: ");
    scanf("%d %d", &start, &end);

    if (SimplePathCheck(G, start, end))
    {
        printf("There is a simple path between %d and %d\n", start, end);
    }
    else
    {
        printf("There is no simple path between %d and %d\n", start, end);
    }

    return 0;
}
