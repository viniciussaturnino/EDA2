# T1: Estabilidade de um algoritmo de ordenação

Um método de ordenação é estável se a ordem relativa de Itens iguais permanece a mesma.

O insertionSort() é um algoritmo estável:

```c
void insertion(int *v, int l, int r) {
    for(int i=r; i>l; i--)
        cmpexch(v[i-1], v[i]);

    for(int i=l+2; i<=r; i++) {
        int j = i;
        int tmp = v[j];
        while (less(tmp, v[j-1])){
            v[j] = v[j-1];
            j--;
        }
        v[j] = tmp;
    }
}
```

Tenhamos um vetor \*v = [5, **3**, 8, 3, 1]

Após a execução do primeiro laço o vetor resultante será: [1, 5, **3**, 8, 3]

Entrando no laço while com i=2 faremos a comparação se o tmp (que vale **3**) que executará apenas uma vez sendo que o **3** é menor apenas que o 5 logo o vetor ficaria assim: [1, **3**, 5, 8, 3]

Nas próximas iterações teremos:

- para i=3: [1, **3**, 5, 8, 3]
- para i=4: [1, **3**, 3, 5, 8]

# T2: Separa

Tendo o vetor: [2, 9, 11, 7, 1]
executando a função separa teremos o vetor: [2, 9, 1, 7, 11] com o pivo sendo o v[3] elemento percebemos que nem todos os elementos anteriores a ele são menores que ele.

Para consertar seria necessário implementar uma versão recursiva do separa, assim teriamos o vetor separado corretamente.
