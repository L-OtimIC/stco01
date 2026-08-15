#include <stdio.h>
#include <string.h> // == <cstring> != <string>

#define MAX 5

struct Produto{
    int codigo;
    char nome[200];
    float preco;
};

int busca(Produto* lista, int n_elementos, int codigo)
{
    for (int i = 0; i < n_elementos; ++i)
        if (lista[i].codigo == codigo)
            return i;
    return -1;
}

int main()
{
    Produto p1[MAX];

    int n_produtos = 0;
    int opcao;
    while(true)
    {
        // printf("0 - finalizar | 1 - inserir | 2 - remover | 3 - buscar | 4 - imprimir\n");
        scanf("%d", &opcao);

        if (opcao == 0)
            break;
        else if (opcao == 1)
        {
            if (n_produtos == MAX)
            {
                printf("Array cheio!\n");
                continue;
            }
            
            Produto aux;
            // printf("Digite codigo nome preco: ");
            scanf("%d %s %f", &(aux.codigo), aux.nome, &(aux.preco));
            p1[n_produtos++] = aux;
        }
        else if (opcao == 2)
        {
            int codigo;
            // printf("Digite codigo de produto a ser removido: ");
            scanf("%d", &codigo);
            int pos = busca(p1, n_produtos, codigo);
            if (pos != -1)
            {
                for (int i = pos; i < n_produtos - 1; i++)
                    p1[i] = p1[i + 1];

                n_produtos--;
            }
        }
        else if (opcao == 3)
        {
            int codigo;
            // printf("Digite codigo de produto a ser buscado: ");
            scanf("%d", &codigo);
            int pos = busca(p1, n_produtos, codigo);
            printf("Elemento%sencontrado. Posicao %d: %d %s %.2f\n", (pos == -1) ? " nao " : " ", pos, p1[pos].codigo, p1[pos].nome, p1[pos].preco);
        }
        else if (opcao == 4)
        {
            for (int i = 0; i < n_produtos; i++)
            {
                printf("Produto #%d: %d %s %.2f\n", i + 1, p1[i].codigo, p1[i].nome, p1[i].preco);
            }
        }
        else if (opcao == 5)
        {
            if (n_produtos == MAX)
            {
                printf("Array cheio!\n");
                continue;
            }

            int pos;
            scanf("%d", &pos);

            if (pos < 0 || pos > n_produtos)
            {
                printf("Posicao invalida\n");
                continue;
            }
            
            Produto aux;
            // printf("Digite codigo nome preco: ");
            scanf("%d %s %f", &(aux.codigo), aux.nome, &(aux.preco));
            for (int i = n_produtos; i > pos; i--)
                p1[i] = p1[i - 1];
            // p1[n_produtos++] = aux;
            p1[pos] = aux;
            n_produtos++;
        }
    }

    return 0;
}