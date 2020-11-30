#include <stdio.h>
#include <stdlib.h>

int *pre, cnt;

typedef struct{int v; int w;}Edge;
typedef struct graph *Graph;

struct graph {int V; int E; int **adj;};

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

void GRAPHInsertE(Graph G, Edge e) {
	int v = e.v, w = e.w;
	if(G->adj[v][w] == 0)
    G->E++;
	G->adj[v][w] = 1;
	G->adj[w][v] = 1;
}

void dfsr(Graph G, Edge e) {
	int t, w = e.w;
	pre[w] = cnt++;
	
	for(t=0; t<G->V; t++)
		if(G->adj[w][t] != 0)
			if(pre[t] == -1)
				dfsr(G,EDGE(w,t));
}

int GRAPHSearch(Graph G) {
    int v, conexos = 0;
    cnt = 0;
    for(v=0; v<G->V; v++)
      pre[v] = -1;
    for(v=0; v<G->V; v++)
        if(pre[v] == -1){
            dfsr(G, EDGE(v,v));
            conexos++;
        }
    return conexos;
}

int main() {
  int n, v, w;
  Edge aresta;
  scanf("%d", &n);
  pre = malloc(n * sizeof(int));
  Graph grafo = GRAPHInit(n);
  while(scanf("%d%d", &v, &w) == 2)
    GRAPHInsertE(grafo, EDGE(v, w));
  printf("%d\n", GRAPHSearch(grafo));
  return 0;
}