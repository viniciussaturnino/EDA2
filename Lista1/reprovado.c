#include <stdio.h>
#include <stdlib.h>

typedef struct alunos{
  char *nome;
  int exercicios;
}alunos;


int main(){
  int n, *v, exercicios;
  char *nome = malloc(20 * sizeof(char));
  alunos *lista;
  scanf("%d", &n);
  lista = malloc(n * sizeof(alunos));
  lista->nome = malloc(20 * sizeof(char));
  for(int i=0; i<n; n++){
    scanf("%s", lista->nome);
    scanf("%d", lista->exercicios);
  }
  return 0;
}