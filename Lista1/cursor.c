#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char **text, opr;
  int n, l, c;
  scanf("%d", &n);
  text = malloc(n * sizeof(char *));
  for(int i=0; i<n; i++)
    text[i] = malloc(1000 * sizeof(char));
  for(int i=0; i<n; i++)
    scanf(" %[^\n]", text[i]);
  scanf("%d %d", &l, &c);
  l--;
  c--;
  while(scanf("%c",&opr)==1){
    if(opr=='k'){
      if(l-1>=0)
        l--;
      if(strlen(text[l])==0)
        printf("%d %d\n", l+1, c+1);
      else if(c>=strlen(text[l]))
        printf("%d %ld %c\n", l+1, strlen(text[l]), text[l][strlen(text[l])-1]);
      else
        printf("%d %d %c\n", l+1, c+1, text[l][c]);
    }
    else if(opr=='j'){
      if(l+1<n)
        l++;
      if(strlen(text[l])==0)
        printf("%d %d\n", l+1, c+1);
      else if(c>=strlen(text[l]))
        printf("%d %ld %c\n", l+1, strlen(text[l]), text[l][strlen(text[l])-1]);
      else
        printf("%d %d %c\n", l+1, c+1, text[l][c]);
    }
  }
  return 0;
}
