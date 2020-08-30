#include <stdio.h>
#include <stdlib.h>

#define less(a, b) (a<b)
#define exch(a, b) {int t = a; a = b; b = t;}
#define cmpexch(a, b) {if(less(b,a)) exch(a, b);}

void insertion(int *v, int l, int r, int h) {
    for(int i=r; i>l; i--)
        cmpexch(v[i-1], v[i]);

    for(int i=l+h; i<=r; i++) {
        int j = i;
        int tmp = v[j];
        while (j>=l+h && less(tmp, v[j-1])){
            v[j] = v[j-h];
            j-=h;
        }
        v[j] = tmp;
    }
}

void shellsort(int *v, int l, int r) {
    for(int i=(r-l)-2; i>0; i-=2)
        insertion(v,l,r,i);
}

int main() {
    int *v, i=0, j;
    v = malloc(sizeof(int));
    while (scanf("%d", &v[i])!=EOF) {
        i++;
        v = realloc(v, (i+1)*sizeof(int));
    }
    
    shellsort(v, 0, i-1);

    for(j=0; j<i-1; j++)
        printf("%d ", v[j]);
    printf("%d\n", v[j]);
    
    return 0;
}