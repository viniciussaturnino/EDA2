#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define key(a) (a.votes)
#define keyC(a) (a.code)
#define less(a, b) (key(a) < key(b))
#define lessC(a, b) (keyC(a) < keyC(b))
#define exch(a, b) { Item t = a; a = b; b = t; }
#define cmpexch(a, b) { if (less(b, a)) exch(a, b); }

typedef struct item {
  int code;
  int votes;
} Item;

int separa(Item *v, int l, int r) {
  Item c = v[r];
  int j = l;
  for(int k=l; k<r; k++) {
    if(v[k].votes == c.votes) {
      if(lessC(v[k], c)) {
        exch(v[k], v[j]);
        j++;
      }
    }
    else {
      if(less(v[k], c)) {
        exch(v[k], v[j]);
        j++;
      }
    }
  }
  exch(v[j], v[r]);
  return j;
}

void quicksort(Item *v, int l, int r) {
  int j;
  if(r <= l)
    return;
  j = separa(v, l, r);
  quicksort(v, l, j - 1);
  quicksort(v, j + 1, r);
}

void quickselect(Item *v, int l, int r, int k) {
  int i;
  if(r<=l)
    return;
  i = separa(v, l, r);
  if(i>k)
    quickselect(v, l, i-1, k);
  if(i<k)
    quickselect(v, i+1, r, k);
}

int main() {
  int sen, fed, est, code, aux, pot, votes, votesPresident, invalidVotes = 0;
  double valid;
  Item president[100];
  Item senador[1000];
  Item DF[10000];
  Item DE[100000];
  
  int x=0;
  while(x<100) {
    president[x].code = x;
    president[x].votes = 0;
    x++;
  }
  x=0;
  while(x<1000) {
    senador[x].code = x;
    senador[x].votes = 0;
    x++;
  }
  x=0;
  while(x<10000) {
    DF[x].code = x;
    DF[x].votes = 0;
    x++;
  }
  x=0;
  while(x<100000) {
    DE[x].code = x;
    DE[x].votes = 0;
    x++;
  }

  scanf("%d %d %d", &sen, &fed, &est);
  while(scanf("%d", &code) == 1) {
    if(code <= 0)
      invalidVotes++;
    else {
      pot = 0;
      aux = code;
      while(code) {
        code/=10;
        pot++;
      }
      switch(pot) {
      case 2:
        president[aux].votes++;
        votes++;
        votesPresident++;
        break;
      case 3:
        senador[aux].votes++;
        votes++;
        break;
      case 4:
        DF[aux].votes++;
        votes++;
        break;
      case 5:
        DE[aux].votes++;
        votes++;
      }
    }
  }
  quickselect(president, 0, 99, 99);
  valid = votesPresident * 0.51;
  printf("%d %d\n", votes, invalidVotes);
  if(president[99].votes < valid)
    printf("Segundo turno\n");
  else
    printf("%d\n", president[99].code);
  quickselect(senador, 0, 999, 999 - sen);
  quicksort(senador, 999 - sen, 999);
  for(int i=0; i<sen; i++)
    printf("%d ", senador[999 - i].code);
  printf("\n");
  quickselect(DF, 0, 9999, 9999 - fed);
  quicksort(DF, 9999 - fed, 9999);
  for(int i=0; i<fed; i++)
    printf("%d ", DF[9999 - i].code);
  printf("\n");
  quickselect(DE, 0, 99999, 99999 - est);
  quicksort(DE, 99999 - est, 99999);
  for(int i=0; i<est; i++)
    printf("%d ", DE[99999 - i].code);
  printf("\n");
  return 0;
}