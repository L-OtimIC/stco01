#include <stdio.h>
#include <stdlib.h>


struct NoDuplo {
    int data;
    NoDuplo* prox;
    NoDuplo* ant;
};

NoDuplo* criar_no_duplo(int valor){
    NoDuplo* novo = (NoDuplo*) malloc(sizeof(NoDuplo));
    novo->data = valor;
    novo->prox = novo->ant = NULL;
    return novo;
}

struct LLigada{
    NoDuplo *head, *tail;
};

NoDuplo* criar_no_duplo(int valor){
    NoDuplo* novo = (NoDuplo*) malloc(sizeof(NoDuplo));
    novo->data = valor;
    novo->prox = novo->ant = NULL;
    return novo;
}

void insere(LLigada* lista, NoDuplo* pos, int valor)
{
    NoDuplo* novo = criar_no_duplo(valor);

    if (lista->head == NULL || pos == NULL)
    {
        lista->head = lista->tail = novo;
        return;
    }

    if (pos == lista->head)
    {
        novo->prox = lista->head;
        lista->head->ant = novo;
        lista->head = novo;
    }
    else if (pos == lista->tail)
    {
        lista->tail->prox = novo;
        novo->ant = lista->tail;
        lista->tail = novo;
    }
    else
    {
        pos->prox->ant = novo;
        novo->prox = pos->prox;
        novo->ant = pos;
        pos->prox = novo;
    }
}

int remover(LLigada* lista, NoDuplo* pos)
{
    int valor = pos->data;
    if(pos == lista->head)
    {
        NoDuplo* temp = lista->head;
        lista->head->prox->ant = NULL;
        lista->head = lista->head->prox;
        free(temp);
    }
    else if (pos == lista->tail)
    {
        NoDuplo* temp = lista->tail;
        lista->tail->ant->prox = NULL;
        lista->tail = lista->tail->ant;
        free(temp);
    }
    else
    {
        pos->ant->prox = pos->prox;
        pos->prox->ant = pos->ant;
        free(pos);
    }
    return valor;
}

int main()
{

    return 0;
}