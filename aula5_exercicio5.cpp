#include <stdio.h>
#include <stdlib.h>

struct List{
    int* data;
    int size;
    int capacity;
};

void create_list(List* lista, int capacity)
{
    lista->capacity = capacity;
    lista->data = (int*) malloc (sizeof(int) * capacity);
    lista->size = 0;
}

void erase_list(List* lista)
{
    free(lista->data);
}

bool insert_list(List* lista, int pos, int valor)
{
    if (lista->size >= lista->capacity || pos < 0 || pos > lista->capacity)
        return false;

    for (int i = lista->capacity; i > pos; --i)
    {
        lista->data[i] = lista->data[i - 1];
    }

    lista->data[pos] = valor;
    lista->size++;
    return true;
}

int remove_list(List* lista, int pos)
{
    // TODO
}

void inverter_list(List* lista)
{
    for (int i = 0; i < lista->size / 2; i++)
    {
        int temp = lista->data[i];
        lista->data[i] = lista->data[lista->size - i - 1];
        lista->data[lista->size - i - 1] = temp;
    }
}

void imprimir_lista(List lista)
{
    printf("L: ");
    for (int i = 0; i < lista.size; i++)
        printf("%4d", lista.data[i]);
    printf("\n");
}

int main()
{
    int op;

    List lista;
    create_list(&lista, 100);

    int pos, valor;

    while(bool continua = true)
    {
        scanf("%d", &op);
        switch(op)
        {
            case 0: // inserir
                scanf("%d %d", &pos, &valor);
                if(insert_list(&lista, pos, valor))
                    printf("Valor inserido com sucesso!\n");

                break;

            case 1: // remover
                scanf("%d", &pos);
                valor = remove_list(&lista, pos);
                printf("Valor removido: %d\n", valor);

                break;

            case 2: // buscar
                // TODO
                break;

            case 3: // imprimir
                imprimir_lista(lista);
                break;

            case 4: // inverter
                inverter_list(&lista);
                break;

            case 5: // ordenar
                // TODO
                break;

            default:
                continua = false;
                break;
        }
    }

    erase_list(&lista);

    return 0;
}