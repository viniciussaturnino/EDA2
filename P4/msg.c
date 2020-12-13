#include <stdio.h>
#include <stdlib.h>

#define key(a) (a.code)
#define less(x,y) (key(x)<key(y))
#define eq(x,y) (key(x)==key(y))
#define exch(x,y){ Mensagem t=x;x=y;y=t; }
#define cmpexch(x,y){ if(less(y,x))exch(x,y); }

typedef struct mensagem {
  int code;
  char c;
} Mensagem;

int separa(Mensagem *v, int l, int r) {
    Mensagem c = v[r];
    int j=l, k;
    for(k=l; k<r; k++)
        if(less(v[k], c)) {
          exch(v[k], v[j]);
          j++;
        }
    exch(v[k], v[j]);
    return j;
}

void quicksort(Mensagem *v, int l, int r) {
    int j;
    if(r<=l)
      return;
    cmpexch(v[(l+r)/2], v[r]);
    cmpexch(v[l], v[(l+r)/2]);
    cmpexch(v[r], v[(l+r)/2]);
    j = separa(v, l,r);
    quicksort(v, l,j-1);
    quicksort(v, j+1,r);
}

void removeRepeat(Mensagem *v, int n) {
  int aux = -1;
  for(int j=0; j<n; j++)
    if(v[j].code != aux) {
      printf("%c", v[j].c);
      aux = v[j].code;
    }
}

int main() {
  long int code, i = 0;
  char c;
  Mensagem *msg;
  msg = malloc(2147483648 * sizeof(Mensagem));
  while(scanf("%ld %c", &code, &c) == 2) {
    msg[i].code = code;
    msg[i].c = c;
    i++;
  }
  quicksort(msg, 0, i-1);
  removeRepeat(msg, i);
  printf("\n");
  return 0;
}