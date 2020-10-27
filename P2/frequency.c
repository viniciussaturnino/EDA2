#include <stdio.h>
#include <stdlib.h>

#define key(a) (a.freq)
#define less(a, b) (key(a)<key(b))
#define exch(a, b) {Frequencies t = a; a = b; b = t;}
#define cmpexch(a, b) {if(less(b,a)) exch(a, b);}

typedef struct frequencies {
  int asc;
  int freq;
} Frequencies;

Frequencies *v;

void insertion(Frequencies *v, int l, int r) {
    for(int i=r; i>l; i--)
        cmpexch(v[i-1], v[i]);

    for(int i=l+2; i<=r; i++) {
        int j = i;
        Frequencies tmp = v[j];
        while (less(tmp, v[j-1])){
            v[j] = v[j-1];
            j--;
        }
        v[j] = tmp;
    }
}

void setVector(int n) {
  v = malloc(n * sizeof(Frequencies));
  for(int i=0; i<n; i++) {
    Frequencies frequency;
    frequency.asc = i+33;
    frequency.freq = 0;
    v[i] = frequency;
  }
}

int main() {
  char c[1001];
  while(scanf(" %s", c) == 1) {
    setVector(95);
    int i=0;
    while(c[i] != '\0'){
      v[c[i] - 33].asc = c[i];
      v[c[i] - 33].freq++;
      i++;
    }
    insertion(v, 0, 94);
    for(int x=0; x<95; x++)
      if(v[x].freq != 0)
        printf("%d %d\n", v[x].asc, v[x].freq);
    printf("\n");
    free(v);
  }
  return 0;
}