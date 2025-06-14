/* This code is a slightly changed version of the code of Chapter 11
of the book
"Data Structures and Program Design in C" by
R. Kruse, C. L. Tondo and B. Leung */



/* global variable visited */
Boolean visited[MAXVERTEX];


/* Traverse: recursive traversal of a graph
   Pre: v is a vertex of graph G
   Post: The depth first traversal, using function Visit, has been
   completed for v and for all vertices adjacent to v.
   Uses: Traverse recursively, Visit */
void Traverse(Graph G, Vertex v, void (*Visit)(Vertex x))
{
  Vertex w;
  Edge *curedge;

  visited[v]=TRUE;
  Visit(v);

  curedge=G.firstedge[v];      /* curedge is a pointer to the first edge (v,_) of V */
  while (curedge){
    w=curedge->endpoint;        /* w is a successor of v and (v,w) is the current edge */
    if (!visited[w]) Traverse(G, w, Visit);
    curedge=curedge->nextedge;  /*curedge is a pointer to the next edge (v,_) of V */
  }
}

/* DepthFirst: depth-first traversal of a graph
   Pre: The graph G has been created.
   Post: The function Visit has been performed at each vertex of G in depth-first order
   Uses: Function Traverse produces the recursive depth-first order */
void DepthFirst(Graph G, void (*Visit)(Vertex x))
{

  Vertex v;

  for (v=0; v < G.n; v++)
    visited[v]=FALSE;
  for (v=0; v < G.n; v++)
    if (!visited[v]) Traverse(G, v, Visit);
}

/* PrintElement: prints the value of its parameter x */
void PrintElement(Vertex x)
{
  printf("%d\n", x);
}
