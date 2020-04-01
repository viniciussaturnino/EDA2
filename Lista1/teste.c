#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char *c;
    struct node *prev;
}Node;

typedef struct queue{
    int size;
    Node *head;
    Node *tail;
}Queue;

Queue* create_queue(){
    Queue queue=(Queue)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;
}

Node* create_node(){
    Node node = (Node)malloc(sizeof(Node));
    node->c = (char*)malloc(sizeof(char)*26);
    node->prev=NULL;
    return node;
}

void push(Queue *queue,Node *node){
    if(node){
        if(queue->size==0){
            queue->head=node;
            queue->tail=node;
        }else{
            queue->tail->prev=node;
            queue->tail=node;
        }
        queue->size++;
    }
}


void print_queue(Queue *queue){
    Node *node = queue->head;
    while(node){
        printf("%s\n",node->c);
        node=node->prev;
    }
}
void verifica(Queue *queue){
    Node *node = queue->head,*aux;
    while(node->prev){
        if(node->c[strlen(node->c)-1]-node->prev->c[0]==32){
            aux=node->prev;
            node->prev=aux->prev;
            aux->prev=NULL;
            push(queue,aux);
            queue->size--;
        }
        node=node->prev;
    }
}


int main(){

    Queue *queue = create_queue();
    Node *node;
    int var;
    char c[26];

    do{
        node = create_node();
        var = scanf(" %s",node->c);
        if(var==EOF){break;}else{
            push(queue,node);
        }
    }while(var!=EOF);

    verifica(queue);

    print_queue(queue);


    return 0;
}


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula{
  char dado[26];
  struct celula *prox;
}celula;

celula *inicializa(){
  celula *novo = malloc(sizeof(celula));
  if(novo!=NULL)
    novo->prox = NULL;
    return novo;
}

void insere(celula *le, char *city, int tam){
  celula *p;
  celula *nova = malloc(sizeof(celula));
  for(int i=0; i<tam; i++)
    nova->dado[i] = city[i];
  for(p=le; p->prox!=NULL; p=p->prox);
  nova->prox = p->prox;
  p->prox = nova;
}

void remove_elemento(celula *le, char *city){
  celula *p;
  for(p=le; p->prox!=NULL&&p->prox->dado!=city; p=p->prox);
  if(p->prox!=NULL){
    celula *tmp = p->prox;
    p->prox = tmp->prox;
    free(tmp);
  }
}

void imprimeList(celula *le){
  for(celula *p=le->prox; p!=NULL; p=p->prox)
      printf("%s\n",p->dado);
}

void organizaLista(celula *le){
  long int tam_str;
  char rem[26];
  celula *ant=le->prox;
  celula *p = ant->prox;
  while(p!=NULL){
    if((p->dado[0])==(ant->dado[strlen(ant->dado)-1]-32)){
      for(int i=0; i<(strlen(p->dado)); i++)
        rem[i] = p->dado[i];
      tam_str = strlen(p->dado);
      remove_elemento(le, p->dado);
      p=p->prox;
      insere(le, rem, tam_str);
    }
    else{
      ant=ant->prox;
      p=p->prox;
    }
  }
}

int main(){
  char city[26];
  long int tam;
  celula *le;
  le = malloc(sizeof(celula));
  while(scanf("%s",city)!=EOF){
    tam = strlen(city);
    insere(le,city,tam);
  }
  organizaLista(le);
  imprimeList(le);
  return 0;
}*/
