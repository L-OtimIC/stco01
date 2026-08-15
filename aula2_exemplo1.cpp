#include <stdio.h>

int fatorial(int n, int profundidade)
{
    for (int i = 0; i < profundidade; i++) printf("  ");
    printf("Entrando fatorial(%d)...\n", n);

    if (n <= 1)
    {
        for (int i = 0; i < profundidade; i++) printf("  ");
        printf("Caso base... Retornando 1\n");

        return 1;
    }

    int resultado = n * fatorial(n - 1, profundidade + 1);

    for (int i = 0; i < profundidade; i++) printf("  ");
    printf("Saindo de fatorial(%d)\n", n);

    return resultado;
}

int main(){

    fatorial(5, 0);

    return 0;
}