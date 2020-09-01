#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
  int *dados;
  int N, topo;
}pilha;

void inicializa(pilha *p){
  p->N = 1;
  p->dados = malloc(p->N * sizeof(int));
  if(p->dados==NULL)
    exit(EXIT_FAILURE);
  p->topo = 0;
}

void empilha(pilha *p, int x){
  if(p->topo == p->N){
    p->dados = realloc(p->dados, 2 * p->N * sizeof(int));
    p->N *= 2;
  }
  p->dados[p->topo] = x;
  p->topo++;
}

int desempilha(pilha *p){
  p->topo--;
  return p->dados[p->topo];
}

/*void imprime(pilha *p){
  printf(" __\n");
  for(int i=p->topo-1; i>=0; i--){
    printf("|");
    printf("%d", p->dados[i]);
    if(p->dados[i]<10)
      printf(" ");
    printf("|\n");
  }
  printf("p->topo = %d\n",p->topo);
}*/

void destroi(pilha *p){
  free(p->dados);
}

int main(){
    pilha p1, p2;
    int n = 1, x, k = 1, aux = 0;
    do{
        k = 1;
        inicializa(&p1);
        inicializa(&p2);
        scanf(" %d",&n);
        if(n == 0)
          return 0;
        aux = 0;
        for(int i=0; i<n; i++){
            scanf(" %d",&x);
            if(x == 0)
              break;
            if(x == k){
                empilha(&p1,x);
                k++;
            }
            else
              empilha(&p2,x);
            while((p2.dados[p2.topo-1] == k) && (p2.topo>0)){
                empilha(&p1,desempilha(&p2));
                k++;
            }
        }
        while(p2.topo != 0)
            empilha(&p1,desempilha(&p2));
        for(int i=0; i<p1.topo-1; i++){
            if((p1.dados[i]) > (p1.dados[i+1])){
                printf("no\n");
                aux = 1;
                break;
            }
        }
        if(aux == 0)
          printf("yes\n");
        destroi(&p1);
        destroi(&p2);
    }while(n!=0);
    return 0;
}
