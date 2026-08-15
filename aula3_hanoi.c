#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hanoi(int n, char O, char D, char T)
{
    if (n == 1)
    {
        printf("Mova %d de %c p/ %c\n", n, O, D);
        return 1;
    }
    else
    {
        int n_movimentos = hanoi(n - 1, O, T, D);
        
        printf("Mova %d de %c p/ %c\n", n, O, D);
        n_movimentos++;

        n_movimentos += hanoi(n - 1, T, D, O);

        return n_movimentos;
    }
}

void permuta(int* arr, int* usado, int n, int pos)
{
    if (pos == n)
    {
        for(int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (usado[i] != 1)
            {
                usado[i] = 1;
                arr[pos] = i;
                permuta(arr, usado, n, pos + 1);
                usado[i] = 0;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int* arr = (int*) malloc (sizeof(int) * n);
    int* usado = (int*) malloc (sizeof(int) * n);

    memset(usado, 0, sizeof(int) * n);
    for (int i = 0; i < n; i++)
        usado[i] = 0;

    permuta(arr, usado, n, 0);

    // printf("# de movimentos: %d\n", hanoi(n, 'O', 'D', 'T'));

    return 0;
}