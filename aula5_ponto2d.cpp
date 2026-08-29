#include <stdio.h>
#include <math.h>

struct Ponto2D{
    double x, y;
};

Ponto2D criar_ponto(double x, double y)
{
    return {x, y};
}

Ponto2D somar(Ponto2D a, Ponto2D b)
{
    return { a.x + b.x, a.y + b.y };
}

double distancia(Ponto2D a, Ponto2D b)
{
    double dx = (a.x - b.x);
    double dy = (a.y - b.y);
    return sqrt(dx * dx + dy * dy);
}

char* ponto_str(Ponto2D p)
{
    char* repr = (char*) malloc (sizeof(char) * 20);
    sprintf(repr, "(%.2lf, %.2lf)", p.x, p.y);
    return repr;
}

int main()
{
    double x, y;

    scanf("%lf %lf", &x, &y);
    Ponto2D a = criar_ponto(x, y);
    scanf("%lf %lf", &x, &y);
    Ponto2D b = criar_ponto(x, y);
    scanf("%lf %lf", &x, &y);
    Ponto2D c = criar_ponto(x, y);

    printf("Distancias:\n - a -> b: %.2lf\n - a -> c: %.2lf\n - b -> c: %.2lf\n",
        distancia(a, b), distancia(a, c), distancia(b, c)
    );

    char* soma_ab = ponto_str(somar(a, b));
    char* soma_ac = ponto_str(somar(a, c));
    char* soma_bc = ponto_str(somar(b, c));
    printf("Somas:\n - a + b: %s \n - a + c: %s\n - b + c: %s\n",
        soma_ab, soma_ac, soma_bc);

    free(soma_ab);
    free(soma_ac);
    free(soma_bc);

    return 0;
}