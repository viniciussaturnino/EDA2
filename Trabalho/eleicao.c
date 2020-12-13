#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define key(a) (a.votos)
#define keyCode(a) (a.code)
#define less(a, b) (key(a) < key(b))
#define lessCode(a, b) (keyCode(a) < keyCode(b))
#define exch(a, b) { Item t = a; a = b; b = t; }
#define cmpexch(a, b) { if (less(b, a)) exch(a, b); }

typedef struct item {
  int code;
  int votos;
} Item;

Item presidente[100];
Item senador[1000];
Item depFed[10000];
Item depEst[100000];
int votos, votospresidente, votosInvalidos;

int separa(Item *vetor, int l, int r) {
  Item c = vetor[r];
  int j = l;
  for (int k = l; k < r; k++) {
    if (vetor[k].votos == c.votos) {
      if (lessCode(vetor[k], c)) {
        exch(vetor[k], vetor[j]);
        j++;
      }
    }
    else {
      if (less(vetor[k], c)) {
        exch(vetor[k], vetor[j]);
        j++;
      }
    }
  }
  exch(vetor[j], vetor[r]);
  return j;
}

void quicksort(Item *vetor, int l, int r) {
  int j;
  if (r <= l)
    return;
  j = separa(vetor, l, r);
  quicksort(vetor, l, j - 1);
  quicksort(vetor, j + 1, r);
}

void quickselect(Item *v, int l, int r, int k) {
  int i;
  if (r <= l)
    return;
  i = separa(v, l, r);
  if (i > k)
    quickselect(v, l, i - 1, k);
  if (i < k)
    quickselect(v, i + 1, r, k);
}

void init() {
  int i;
  for (i = 0; i < 100; i++) {
    presidente[i].code = i;
    presidente[i].votos = 0;
  }
  for (i = 0; i < 1000; i++) {
    senador[i].code = i;
    senador[i].votos = 0;
  }
  for (i = 0; i < 10000; i++) {
    depFed[i].code = i;
    depFed[i].votos = 0;
  }
  for (i = 0; i < 100000; i++) {
    depEst[i].code = i;
    depEst[i].votos = 0;
  }
}

int main() {
  int S, F, E, codigo, auxCod, pot;
  double presidenteInd, presidenteValid;
  init();
  scanf(" %d %d %d", &S, &F, &E);
  while (scanf("%d", &codigo) != EOF) {
    if (codigo <= 0)
      votosInvalidos++;
    else {
      pot = 0;
      auxCod = codigo;
      while (codigo) {
        codigo /= 10;
        pot++;
      }
      switch (pot) {
      case 2:
        presidente[auxCod].votos++;
        votos++;
        votospresidente++;
        break;
      case 3:
        senador[auxCod].votos++;
        votos++;
        break;
      case 4:
        depFed[auxCod].votos++;
        votos++;
        break;
      case 5:
        depEst[auxCod].votos++;
        votos++;
      }
    }
  }
  quickselect(presidente, 0, 99, 99);
  presidenteValid = votospresidente * 0.51;
  printf("%d %d\n", votos, votosInvalidos);
  if (presidente[99].votos < presidenteValid)
    printf("Segundo turno\n");
  else
    printf("%d\n", presidente[99].code);
  quickselect(senador, 0, 999, 999 - S);
  quicksort(senador, 999 - S, 999);
  for (int i = 0; i < S; i++)
    printf("%d ", senador[999 - i].code);
  printf("\n");
  quickselect(depFed, 0, 9999, 9999 - F);
  quicksort(depFed, 9999 - F, 9999);
  for (int i = 0; i < F; i++)
    printf("%d ", depFed[9999 - i].code);
  printf("\n");
  quickselect(depEst, 0, 99999, 99999 - E);
  quicksort(depEst, 99999 - E, 99999);
  for (int i = 0; i < E; i++)
    printf("%d ", depEst[99999 - i].code);
  printf("\n");
  return 0;
}