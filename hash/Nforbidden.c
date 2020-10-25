#include <stdio.h>
#include <stdlib.h>

int v[262139];

int hashN(int n) {
  return n%262139;
}

int main() {
  int n, c;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    int t;
    scanf("%d", &t);
    v[hashN(t)] = t;
  }
  while(scanf("%d", &c) == 1) {
    int t = hashN(c);
    if(v[t] == c)
      printf("sim\n");
    else if(v[t] == 0)
      printf("nao\n");
    else if(v[t] != c)
      printf("colisao\n");
  }
  return 0;
}