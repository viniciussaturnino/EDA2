#include <stdio.h>
#include <stdlib.h>

int *pre, cnt;

typedef struct{int v; int w;}Edge;
typedef struct graph *Graph;

struct graph {int V; int E; int **adj; int **tc;};

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
	if(option == 0)
    return;
  int v = e.v, w = e.w;
	if(G->adj[v][w] == 0)
    G->E++;
  if(option == 1)
	  G->adj[v][w] = 1;
	if(option == 2){
    G->adj[v][w] = 1;
    G->adj[w][v] = 1;
  }
}

void GRAPHtc(Graph G){
    int i,s,t;
    G->tc = malloc(G->V * sizeof(int *));
    for(int x=0; x<G->V; x++)
      G->tc[x] = malloc(G->V * sizeof(int));
    for(s=0;s<G->V;s++)
        for(t=0;t<G->V;t++)
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

int GRAPHreach(Graph G, int s, int t){
    return G->tc[s][t];
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
  int n, v, w, d;
  int ida, volta;
  Edge aresta;
  scanf("%d", &n);
  pre = malloc(n * sizeof(int));
  Graph grafo = GRAPHInit(n);
  scanf("%d%d%d", &v, &w, &d);
  while(!(v == 0 && w == 0 && d == 0)) {
    GRAPHInsertE(grafo, EDGE(v, w), d);
    scanf("%d%d%d", &v, &w, &d);
  }
  GRAPHtc(grafo);
  while(scanf("%d%d", &v, &w) == 2) {
    ida = GRAPHreach(grafo, v, w);
    volta =  GRAPHreach(grafo, w, v);
    if(ida == 1 && volta == 1)
      printf("Ida e Volta\n");
    else if(ida == 1)
      printf("Apenas Ida\n");
    else if(volta == 1)
      printf("Apenas Volta\n");
    else
      printf("Impossibru\n");
  }
  return 0;
}