#include <stdio.h>
#include <stdlib.h>

#define less(a, b) (a<b)
#define lessequals(a, b) (a<=b)
#define exch(a, b) {int t = a; a = b; b = t;}
#define cmpexch(a, b) {if(less(b,a)) exch(a, b);}

int separa(int *v, int l, int r) {
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

void quicksort(int *v, int l, int r) {
    int j;
    if(r<=l) return;
    j = separa(v, l, r);
    quicksort(v, l, j-1);
    quicksort(v, j+1, r);
}

int main() {
    int *v, i=0, j;
    v = malloc(sizeof(int));
    while (scanf("%d", &v[i])!=EOF) {
        i++;
        v = realloc(v, (i+1)*sizeof(int));
    }
    
    quicksort(v, 0, i-1);

    for(j=0; j<i-1; j++)
        printf("%d ", v[j]);
    printf("%d\n", v[j]);
    
    return 0;
}