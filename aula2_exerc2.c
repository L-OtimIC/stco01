#include <stdio.h>

void contagem(int n)
{
    if (n == 0)
        printf("Fogo!\n");
    else
    {
        contagem(n-1);
        printf("%d...", n);
    }
}

float potencia(float base, int expoente)
{
    if (expoente == 0)
        return 1;
    else
    {
        return base * potencia(base, expoente - 1);
    }
}

float potencia_iterativa(float base, int expoente)
{
    float res = 1;
    for (int i = 0; i < expoente; i++)
        res *= base;
    return res;
}

int main()
{
    // int n;
    // scanf("%d", &n);
    // contagem(n);

    float base;
    int exp;
    scanf("%f %d", &base, &exp);

    printf("b^e iterativa = %f\n", potencia_iterativa(base,exp));
    fflush(stdout);

    printf("b^e recursiva = %f\n", potencia(base, exp));
}