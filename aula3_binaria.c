#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* buscabinaria(int* v, int n, int x, int* contador)
{
    if (n == 0) return NULL;

    int meio = n / 2;
    if (v[meio] == x)
        return v + meio;
    else{
        if (v[meio] > x)
        {
            (*contador)++;
            return buscabinaria(v, n/2, x, contador);
        }
        else
        {
            (*contador)++;
            return buscabinaria(v + n/2 + 1, n/2, x, contador);
        }
    }
}

int* buscalinear(int* v, int n, int x)
{
    int contador = 0, i;
    for (i = 0; i < n; i++)
    {
        contador++;
        if (v[i] == x)
            break;
    }
    printf("Contador Linear: %d\n", contador);
    if (i < n)
        return v + i;
    return NULL;
}

int comp(const void* a, const void* b) { return *((int*)a) > *((int*)b); }

int main()
{
    int v[20];
    srand(time(NULL));

    for (int i = 0; i < 20; i++)
    {
        v[i] = rand() % 100;
    }
    qsort(v, 20, sizeof(int), comp);

    for (int i = 0; i < 20; i++)
    {
        printf("%4d", v[i]);
    }
    printf("\n");

    int x;
    while(1)
    {
        scanf("%d", &x);
        if (x == -1) break;

        int contador = 0;
        int* elemento = buscabinaria(v, 20, x, &contador);
        printf("Contador binária: %d\n", contador);
        elemento = buscalinear(v, 20, x);
        if (elemento == NULL)
        {
            printf("Elemento não encontrado\n");
        }
        else
        {
            printf("Elemento encontrado %p : %d\n", elemento, *elemento);
        }
    }
}