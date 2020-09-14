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

int main(){
    int *v,n;
    scanf("%d",&n);
    v = malloc(n*sizeof(int));

    for(int i=0; i<n; i++)
      scanf("%d", &v[i]);

    quicksort(v, 0, n-1);

    printf("%d", v[0]);
    for(int i=1; i<n; i++)
        printf(" %d", v[i]);
    printf("\n");

    return 0;
}