#include <stdio.h>
#include <stdlib.h>

int *pre, cnt, maior = 0, menorV, isJoao, currentJao;

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

void dfsr(Graph G, Edge e, int j) {
	int t, w = e.w;
	pre[w] = cnt++;
	if(w == j)
    currentJao = 1;
	for(t=0; t<G->V; t++)
		if(G->adj[w][t] != 0)
			if(pre[t] == -1)
				dfsr(G, EDGE(w,t), j);
}

void GRAPHSearch(Graph G, int j) {
    int v;
    for(v=0; v<G->V; v++)
      pre[v] = -1;
    for(v=0; v<G->V; v++) {
      currentJao = 0;
      cnt = 0;
      if(pre[v] == -1) {
        dfsr(G, EDGE(v,v), j);
        if(cnt >= maior) {
          if(v == 0 || cnt > maior) {
            maior = cnt;
            menorV = v;
            isJoao = currentJao;
          }
          else if(cnt == maior) {
            if(currentJao == 1) {
              maior = cnt;
              menorV = v;
              isJoao = 1;
            }
            else if(!isJoao && (v < menorV)) {
              maior = cnt;
              menorV = v;
              isJoao = 0;
            }
          }
        }
      }
    }
}

int main() {
  int n, j, v, w;
  scanf("%d%d", &n, &j);
  pre = malloc(n * sizeof(int));
  Graph grafo = GRAPHInit(n);
  while(scanf("%d%d", &v, &w) == 2)
    GRAPHInsertE(grafo, EDGE(v, w));
  GRAPHSearch(grafo, j);
  if(isJoao == 1) {
    if(maior == 1)
      printf("Fique em casa\n");
    else
      printf("Bora pra estrada\n");
  }
  else
    printf("Vamos para %d\n", menorV);
  return 0;
}