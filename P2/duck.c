#include <stdio.h>
#include <stdlib.h>

int *v;

int hashN(int n, int mod) {
  return n%mod;
}

void setVector(int n) {
  v = calloc(n, sizeof(int));
}

int main() {
  int n, code, h, majority;
  scanf("%d", &n);
  while(n!=0) {
    setVector(n);
    for(int i=0; i<n; i++) {
      scanf("%d", &code);
      if(i==0)
        majority = code;
      v[hashN(code, n)]++;
      if(v[hashN(code, n)] > v[hashN(majority, n)])
        majority = code;
    }
    printf("%d\n", majority);
    scanf("%d", &n);
    free(v);
  }
  return 0;
}