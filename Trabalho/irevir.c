#include <stdio.h>
#include <stdlib.h>

typedef struct{int v; int w;}Edge;

struct graph {int V; int E; int **adj; int **tc;};
typedef struct graph *Graph;

Graph GRAPHInit(int V) {
	Graph G = malloc(sizeof(*G));
	G->V = V;
  G->E = 0;
	G->adj = malloc(V * sizeof(int *));
  for(int i=0; i<V; i++)
    G->adj[i] = malloc(V * sizeof(int));
	return G;
}

Edge EDGE(int x, int y) {
  Edge aresta;
  aresta.v = x;
  aresta.w = y;
  return aresta;
}

void GRAPHInsertE(Graph G, Edge e, int option) {
  int v = e.v, w = e.w;
	if(G->adj[v][w] == 0)
    G->E++;
  if(option == 1)
	  G->adj[v][w] = 1;
	if(option == 2) {
    G->adj[v][w] = 1;
    G->adj[w][v] = 1;
  }
}

void GRAPHtc(Graph G) {
    int i, s, t;
    G->tc = malloc(G->V * sizeof(int *));
    for(int x=0; x<G->V; x++)
      G->tc[x] = malloc(G->V * sizeof(int));
    for(s=0; s<G->V; s++)
        for(t=0; t<G->V; t++)
            G->tc[s][t] = G->adj[s][t];
    for(s=0; s<G->V; s++)
      G->tc[s][s] = 1;
    for(i=0; i<G->V; i++)
        for(s=0; s<G->V; s++)
            if(G->tc[s][i] == 1)
                for(t=0; t<G->V; t++)
                    if(G->tc[i][t] == 1)
                        G->tc[s][t] = 1;
}

int main() {
  int n = 1, c, m, v, w, p;
  Graph grafo;
  while(n != 0) {
    c = 1;
    scanf("%d", &n);
    if(n==0)
      break;
    scanf("%d", &m);
    grafo = GRAPHInit(n);
    for(int i=0; i<m; i++) {
      scanf("%d %d %d", &v, &w, &p);
      GRAPHInsertE(grafo, EDGE(v-1, w-1), p);
    }
    GRAPHtc(grafo);
    for(int i=0; i<grafo->V; i++)
      for(int j=0; j<grafo->V; j++)
        if(grafo->tc[i][j] == 0)
          c = 0;
    if(c)
      printf("1\n");
    else
      printf("0\n");
    free(grafo);
  }
  return 0;
}