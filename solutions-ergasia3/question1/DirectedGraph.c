#include <stdio.h>
#include <stdlib.h>
#include "GraphTypes.h"
#include "Queue.h"

/* Πρωτότυπα συναρτήσεων */
void DepthFirstOrder(Graph G, Vertex *T);
void DFSTraverse(Graph G, Vertex v, Vertex *T, int *index);

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

/* Τοπολογική ταξινόμηση χρησιμοποιώντας BFS */
void BreadthTopSort(Graph G, Vertex *T)
{
    int predecessorcount[MAXVERTEX];
    Queue Q;
    Vertex v, succ;
    Edge *curedge;
    int place;

    for (v = 0; v < G.n; v++)
        predecessorcount[v] = 0;

    for (v = 0; v < G.n; v++)
        for (curedge = G.firstedge[v]; curedge; curedge = curedge->nextedge)
            predecessorcount[curedge->endpoint]++;

    InitializeQueue(&Q);

    for (v = 0; v < G.n; v++)
        if (predecessorcount[v] == 0)
            Insert(v, &Q);

    place = -1;
    while (!Empty(&Q))
    {
        Remove(&Q, &v);
        place++;
        T[place] = v;

        for (curedge = G.firstedge[v]; curedge; curedge = curedge->nextedge)
        {
            succ = curedge->endpoint;
            predecessorcount[succ]--;
            if (predecessorcount[succ] == 0)
                Insert(succ, &Q);
        }
    }
}

/* Αντιστροφη της κατεύθυνσης όλων των ακμών στον γράφο */
Graph GraphReverse(Graph G)
{
    Graph R;
    Initialize(&R, G.n);
    for (int v = 0; v < G.n; v++)
    {
        Edge *curedge = G.firstedge[v];
        while (curedge)
        {
            InsertEdge(&R, curedge->endpoint, v);
            curedge = curedge->nextedge;
        }
    }
    return R;
}

/* Υπολογισμος των ισχυρων συνεκτικά συνιστωσων */
void Kosaraju(Graph G, int *sc)
{
    Graph R = GraphReverse(G); 
    Vertex T[MAXVERTEX];
    DepthFirstOrder(G, T); 

    for (int v = 0; v < G.n; v++)
        visited[v] = FALSE;

    int component = 0;
    for (int i = G.n - 1; i >= 0; i--)
    {
        if (!visited[T[i]])
        {
            component++;
            TraverseComponent(R, T[i], sc, component); 
        }
    }
}

void TraverseComponent(Graph G, Vertex v, int *sc, int component)
{
    Vertex w;
    Edge *curedge;

    visited[v] = TRUE;
    sc[v] = component;

    curedge = G.firstedge[v];
    while (curedge)
    {
        w = curedge->endpoint;
        if (!visited[w])
            TraverseComponent(G, w, sc, component);
        curedge = curedge->nextedge;
    }
}

void DepthFirstOrder(Graph G, Vertex *T)
{
    int index = G.n - 1;
    for (int v = 0; v < G.n; v++)
        visited[v] = FALSE;
    for (int v = 0; v < G.n; v++)
        if (!visited[v])
            DFSTraverse(G, v, T, &index);
}

void DFSTraverse(Graph G, Vertex v, Vertex *T, int *index)
{
    visited[v] = TRUE;
    Edge *curedge = G.firstedge[v];
    while (curedge)
    {
        Vertex w = curedge->endpoint;
        if (!visited[w])
            DFSTraverse(G, w, T, index);
        curedge = curedge->nextedge;
    }
    T[(*index)--] = v;
}
