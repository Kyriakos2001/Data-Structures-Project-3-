#ifndef GRAPHTYPES_H
#define GRAPHTYPES_H

#define MAXVERTEX 20

typedef enum
{
    FALSE,
    TRUE
} Boolean;

typedef int Vertex;

typedef struct edge
{
    Vertex endpoint;
    struct edge *nextedge;
} Edge;

typedef struct graph
{
    int n; 
    Edge *firstedge[MAXVERTEX];
} Graph;

void Initialize(Graph *G, int n);
void InsertEdge(Graph *G, Vertex u, Vertex v);
void ShowGraph(Graph G);
void DepthFirst(Graph G, void (*Visit)(Vertex x));
Boolean SimplePathCheck(Graph G, Vertex u, Vertex v);
void PrintElement(Vertex x);

#endif
