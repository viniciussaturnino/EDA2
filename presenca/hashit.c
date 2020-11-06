#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
char NULL_VALUE[] = "NULL_VALUE";

int hashN(char strValue[15]) {
  int i=0, s=0;
  while(strValue[i] != '\0') {
    s+=strValue[i] * (i+1);
    i++;
  }
  s*=19;
  return s%101;
}

int findInTable(char table[101][15], char strValue[15]) {
  int hash = hashN(strValue);
  int j=0, index;
  while(j<20) {
    index = (hash + (j*j) + (23*j))%101;
    if(strcmp(table[index], strValue) == 0)
      return index;
    j++;
  }
  return -1;
}

void insert(char table[101][15], char strValue[15]) {
  if(findInTable(table, strValue) != -1)
    return;
  int hash = hashN(strValue);
  int j=0, pos;
  while(j<20) {
    pos = (hash + (j*j) + (23*j))%101;
    if(strcmp(table[pos], NULL_VALUE) == 0) {
      strcpy(table[pos], strValue);
      N++;
      return;
    }
    j++;
  }
}

void delete(char table[101][15], char strValue[15]) {
  int index = findInTable(table, strValue);
  if(index == -1)
    return;
  strcpy(table[index], NULL_VALUE);
  N--;
}

void init(char table[101][15]) {
	N=0;
  for(int i=0; i<101; i++)
    strcpy(table[i], NULL_VALUE);
}

int main() {
  int qtd, i, t;
  char str1[19], str2[3], str3[15];
  int codigo;
  scanf("%d", &t);
  for(int x=0; x<t; x++){
    char table[101][15];
    init(table);
    scanf("%d", &qtd);
    for(i=0; i<qtd; i++) {
        scanf("%s", str1);
        strncpy(str2, str1, 3);
        strncpy(str3, str1+4, 15);
        if(str2[0] == 'A')
            insert(table, str3);
        else
            delete(table, str3);
    }
    printf("%d\n", N);
    for(i=0; i<101; i++)
        if(strcmp(table[i], NULL_VALUE) != 0)
            printf("%d:%s\n", i, table[i]);
  }
  return 0;
}