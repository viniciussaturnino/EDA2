#include <stdio.h>
#include <stdlib.h>

int sep( int v[], int p, int r) {
  int q, i, j, t;
  i = p; q = (p + r) / 2; j = r;
  do {
    while (v[i] < v[q])
      ++i;
    while (v[j] > v[q])
      --j;
    if (i <= j) {
      t = v[i], v[i] = v[j], v[j] = t;
      ++i, --j;
    }
  } while (i <= j);
  return i;
}

int main() {
  int v[5] = {5, 4, 3, 2, 1};
  int t = sep(v, 0, 4);
  for(int i=0; i<5; i++)
    printf("%d ", v[i]);
  printf("\n");
  printf("%d\n", t);
  return 0;
}