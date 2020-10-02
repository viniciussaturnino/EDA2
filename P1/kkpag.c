#include <stdio.h>
#include <stdlib.h>

#define less(a, b) (a<b)
#define lessequals(a, b) (a<=b)
#define exch(a, b) {int t = a; a = b; b = t;}
#define cmpexch(a, b) {if(less(b,a)) exch(a, b);}

int sep(int *v, int l, int r) {
    int i=l-1, j=r, c = v[r];
    for(;;){
        while (less(v[++i], c));
        while (less(c, v[--j])) if(j==l) break;
        if(i>=j) break;
        exch(v[i], v[j]);
    }
    exch(v[i], v[r]);
    return i;
}

void quickSelect(int *v, int l, int r, int k) {
  int i;
  i = sep(v, l, r);
  if(r<=l)
    return;
  if(i>k)
    quickSelect(v, l, i-1, k);
  if(i<k)
    quickSelect(v, i+1, r, k);
}

void quicksort(int *v, int l, int r){
    int j;
    if(r<=l)
      return;
    
    cmpexch(v[(l+r)/2],v[r]);
    cmpexch(v[l],v[(l+r)/2]);
    cmpexch(v[r],v[(l+r)/2]);

    j = sep(v,l,r);
    quicksort(v,l,j-1);
    quicksort(v,j+1,r);
}

int main() {
  int n, p, x, *v, aux;
  scanf("%d %d %d", &n, &p, &x);
  v = malloc(n * sizeof(int));
  for(int i=0; i<n; i++)
    scanf("%d", &v[i]);
  aux = p*x;
  quickSelect(v, 0, n-1, aux);
  quicksort(v, aux, n-1);
  for(int i=0; i<x && aux<n; i++) {
    printf("%d\n", v[aux]);
    aux++;
  }
  return 0;
}