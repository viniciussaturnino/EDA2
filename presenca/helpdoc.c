#include <stdio.h>

int main() {
  int n, s=0, x, try;
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &x);
    s += x;
  }
  scanf("%d", &try);
  if(try == s)
    printf("Acertou\n");
  else
    printf("Errou\n");
  return 0;
}