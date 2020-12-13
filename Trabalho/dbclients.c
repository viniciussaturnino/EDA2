#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char table[7999][101];
int N;
char null[] = "null";

int hash(char email[101]) {
  int i = 0, s = 0, add = 1;
  while(email[i] != '\0') {
    if(email[i] == '+')
      add = 0;
    if(email[i] == '@') {
      add = 2;
      i++;
    }
    if(add == 1)
      if(email[i] != '.')
        s += email[i];
    if(add == 2)
      s += email[i];
    i++;
  }
  return s%7999;
}

void insere(char email[101]) {
  int hashedValue = hash(email);
  if(strcmp(table[hashedValue], null) == 0) {
    strcpy(table[hashedValue], email);
    N++;
    return;
  }
  while(strcmp(table[hashedValue], email) != 0) {
    if(strcmp(table[hashedValue], null) == 0) {
      strcpy(table[hashedValue], email);
      N++;
      return;
    }
    hashedValue++;
  }
}

int main() {
  int n, oldIndex, newIndex, add;
  char email[101], novo[101];
  scanf("%d", &n);
  int i=0;
  while(i<7999) {
    strcpy(table[i], null);
    i++;
  }
  i = 0;
  while(i<n) {
    scanf("%s", email);
    oldIndex = 0;
    newIndex = 0;
    add = 1;
    for(oldIndex=0; email[oldIndex]!='\0'; oldIndex++){
      if(email[oldIndex] == '+')
        add = 0;
      if(email[oldIndex] == '@') {
        add = 2;
        oldIndex++;
      }
      if(add == 1)
        if(email[oldIndex] != '.') {
          novo[newIndex] = email[oldIndex];
          newIndex++;
        }
      if(add == 2) {
        novo[newIndex] = email[oldIndex];
        newIndex++;
      }
    }
    novo[newIndex] = email[oldIndex];
    insere(novo);
    i++;
  }
  printf("%d\n", N);
  return 0;
}