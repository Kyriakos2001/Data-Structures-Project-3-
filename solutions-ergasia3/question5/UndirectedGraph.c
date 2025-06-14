#include <stdio.h>
#include <stdlib.h>
#include "GraphTypes.h"

/* Αρχικοποιηση του γράφου */
void Initialize(Graph *G, int n)
{
    G->n = n;
    for (int i = 0; i < n; i++)
    {
        G->firstedge[i] = NULL;
    }
}

/* Εισαγωγη μιας ακμής στον γράφο */
void InsertEdge(Graph *G, Vertex u, Vertex v)
{
    Edge *newEdge = (Edge *)malloc(sizeof(Edge));
    newEdge->endpoint = v;
    newEdge->nextedge = G->firstedge[u];
    G->firstedge[u] = newEdge;

    newEdge = (Edge *)malloc(sizeof(Edge));
    newEdge->endpoint = u;
    newEdge->nextedge = G->firstedge[v];
    G->firstedge[v] = newEdge;
}

/* Εκτυπωση του γράφου */
void ShowGraph(Graph G)
{
    for (int i = 0; i < G.n; i++)
    {
        printf("Vertex %d: ", i);
        Edge *edge = G.firstedge[i];
        while (edge != NULL)
        {
            printf(" %d", edge->endpoint);
            edge = edge->nextedge;
        }
        printf("\n");
    }
}

/* Διάσχιση του γράφου με πρώτα κατά βάθος */
Boolean visited[MAXVERTEX];

void Traverse(Graph G, Vertex v, void (*Visit)(Vertex x))
{
    Vertex w;
    Edge *curedge;

    visited[v] = TRUE;
    Visit(v);

    curedge = G.firstedge[v];
    while (curedge)
    {
        w = curedge->endpoint;
        if (!visited[w])
            Traverse(G, w, Visit);
        curedge = curedge->nextedge;
    }
}

void DepthFirst(Graph G, void (*Visit)(Vertex x))
{
    Vertex v;
    for (v = 0; v < G.n; v++)
        visited[v] = FALSE;
    for (v = 0; v < G.n; v++)
        if (!visited[v])
            Traverse(G, v, Visit);
}

void PrintElement(Vertex x)
{
    printf("%d ", x);
}

/* Ελεγχος για ένα απλό μονοπάτι μεταξύ δύο κορυφών */
Boolean SimplePathCheckUtil(Graph G, Vertex u, Vertex v, Boolean *visited)
{
    if (u == v)
        return TRUE;
    visited[u] = TRUE;

    Edge *curedge = G.firstedge[u];
    while (curedge)
    {
        if (!visited[curedge->endpoint])
        {
            if (SimplePathCheckUtil(G, curedge->endpoint, v, visited))
            {
                return TRUE;
            }
        }
        curedge = curedge->nextedge;
    }
    return FALSE;
}

Boolean SimplePathCheck(Graph G, Vertex u, Vertex v)
{
    for (int i = 0; i < G.n; i++)
    {
        visited[i] = FALSE;
    }
    return SimplePathCheckUtil(G, u, v, visited);
}
