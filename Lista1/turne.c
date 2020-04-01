#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula{
  char *dado;
  struct celula *prox;
}celula;

typedef struct fila{
  int tam;
  celula *head;
  celula *tail;
}fila;

celula *criaCelula(){
  celula *l = malloc(sizeof(celula));
  l->dado = malloc(26 * sizeof(char));
  l->prox = NULL;
  return l;
}

fila *criaFila(){
  fila *f = malloc(sizeof(fila));
  f->head = NULL;
  f->tail = NULL;
  f->tam = 0;
  return f;
}

void enfileira(fila *f, celula *l){
  if(l){
    if(f->tam == 0){
      f->head = l;
      f->tail = l;
    }
    else{
      f->tail->prox = l;
      f->tail = l;
    }
    f->tam++;
  }
}

void organizaLista(fila *f){
  for(celula *p=f->head; p->prox!=NULL; p=p->prox)
    if(p->prox->dado[0] == p->dado[strlen(p->dado)-1]-32){
      celula *aux = p->prox;
      p->prox = aux->prox;
      aux->prox = NULL;
      enfileira(f,aux);
      f->tam--;
    }
}

void imprimeList(fila *f){
  for(celula *p=f->head; p!=NULL; p=p->prox)
    printf("%s\n",p->dado);
}

int main(){
  fila *fila = criaFila();
  celula *l;
  char city[26];
  int aux;
  do {
    l = criaCelula();
    aux = scanf("%s",l->dado);
    if(aux==EOF)
      break;
    else
      enfileira(fila,l);
  } while(aux != EOF);
  organizaLista(fila);
  imprimeList(fila);
  return 0;
}
