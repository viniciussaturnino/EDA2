#include <stdio.h>
#include <stdlib.h>

#define key(a) (a.nota)
#define keycod(a) (a.codigo)
#define less(x,y) (key(x)<key(y))
#define lesscod(x,y) (keycod(x)<keycod(y))
#define eq(x,y) (key(x)==key(y))
#define exch(x,y){ Semente t=x;x=y;y=t; }
#define cmpexch(x,y){ if(less(y,x))exch(x,y); }

typedef struct semente {
  int codigo;
  int nota;
} Semente;

int separa(Semente *sementes, int l, int r) {
    Semente c = sementes[r];
    int j=l, k;
    for(k=l; k<r; k++){
        if(less(sementes[k], c)) {
          exch(sementes[k], sementes[j]);
          j++;
        }
        if(eq(sementes[k], c)) {
          if(lesscod(sementes[k], c)) {
            exch(sementes[k], sementes[j]);
            j++;
          }
        }
    }
    exch(sementes[k], sementes[j]);
    return j;
}

int novoSepara(Semente *sementes, int l, int r) {
    Semente c = sementes[r];
    int j=l, k;
    for(k=l; k<r; k++)
        if(lesscod(sementes[k], c)) {
            exch(sementes[k], sementes[j]);
            j++;
        }
    exch(sementes[k], sementes[j]);
    return j;
}

void quickselect(Semente *v, int l, int r, int n) {
  int i;
  if (r <= l)
    return;
  i = separa(v, l, r);
  if (i > n)
    quickselect(v, l, i-1, n);
  if (i < n)
    quickselect(v, i+1, r, n);
}

void quicksort(Semente *sementes, int l, int r) {
    int j;
    if(r<=l)
      return;
    cmpexch(sementes[(l+r)/2], sementes[r]);
    cmpexch(sementes[l], sementes[(l+r)/2]);
    cmpexch(sementes[r], sementes[(l+r)/2]);
    j = novoSepara(sementes, l,r);
    quicksort(sementes, l,j-1);
    quicksort(sementes, j+1,r);
}

int main() {
  int n, codigo, nota, i=0;
  Semente semente;
  scanf("%d", &n);
  Semente *sementes = malloc(10000 * sizeof(Semente));
  while(scanf("%d %d", &codigo, &nota) == 2) {
    sementes[i].codigo = codigo;
    sementes[i].nota = nota;
    i++;
  }
  quickselect(sementes, 0, i-1, n-1);
  quicksort(sementes, 0, n-1);
  for(int j=0; j<n; j++)
    printf("%d %d\n", sementes[j].codigo, sementes[j].nota);
  return 0;
}