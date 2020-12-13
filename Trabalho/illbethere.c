#include <stdio.h>
#include <stdlib.h>

typedef struct{int v; int w;}Edge;
typedef struct graph *Graph;
struct graph {int **adj; int **tc;};

Graph GRAPHInit(int V) {
	Graph G = malloc(sizeof(*G));
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
  G->adj[e.v][e.w] = 1;
  G->adj[e.w][e.v] = 1;
}

int main() {
  int n, m, j, *v, *pre, a, aux;
  Graph grafo;
  scanf("%d %d %d", &n, &m, &j);
  v = calloc(m, sizeof(int));
  pre = calloc(n, sizeof(int));
  grafo = GRAPHInit(n);
  int i = 0;
  while(i<n) {
    scanf("%d", &a);
    for(int x=0; x<a; x++) {
      scanf("%d", &aux);
      GRAPHInsertE(grafo, EDGE(i, aux));
    }
    i++;
  }
  i = 0;
  while(i<m) {
    scanf("%d", &v[i]);
    pre[v[i]] = 1;
    for(int x=0; x<n; x++)
      if(grafo->adj[v[i]][x] == 1)
        pre[x] = 1;
    i++;
  }
  i = 0;
  while(i<j) {
    scanf("%d",&aux);
    if(pre[aux] == 1)
        printf("Eu vou estar la\n");
    else
        printf("Nao vou estar la\n");
    i++;
  }
  return 0;
}