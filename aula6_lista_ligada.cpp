#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct No{
    int dado;
    No* prox;
};

struct Lista{
    No* cabeca, *cauda;
    int tamanho;
};

No* criar_no(int valor)
{
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("Acabou a memoria!\n");
        return NULL;
    }
    novo->dado = valor;
    novo->prox = NULL;

    return novo;
}

void inserir_fim(Lista* L, int valor)
{
    if ((L->tamanho == 0) || L->cabeca == NULL && L->cauda == NULL)
    {
        L->cabeca = criar_no(valor);
        L->cauda = L->cabeca;
    }
    else
    {
        L->cauda->prox = criar_no(valor);
        L->cauda = L->cauda->prox;
    }
    L->tamanho++;
}

int remover_meio(Lista* L, No* elemento)
{
    if (L->cabeca == NULL || elemento == NULL)
    {
        return INT_MIN;
    }
    int valor = elemento->dado;
    if (L->tamanho == 1) // Lista unitária
    {
        free(elemento);
        L->cabeca = L->cauda = NULL;
    }
    else if (elemento == L->cabeca) // Remove no inicio
    {
        L->cabeca = elemento->prox;
        free(elemento);
    }
    else if (elemento == L->cauda) // Remove no final
    {
        No* aux = L->cabeca;
        while(aux->prox != L->cauda) aux = aux->prox;
        aux->prox = NULL;
        L->cauda = aux;
        free(elemento);
    }
    else // Remove no meio
    {
        No* aux;
        for (aux = L->cabeca; aux->prox != elemento; aux = aux->prox) ;
        // No* aux = L->cabeca;
        // while(aux->prox != elemento) aux = aux->prox;
        aux->prox = elemento->prox;
        free(elemento);
    }
    L->tamanho--;
    return valor;
}


void inserir_ordenado(Lista* L, int valor)
{
    No* novo = criar_no(valor), *aux;
    for (aux = L->cabeca; aux->prox != NULL; aux = aux->prox)
    {
        if (aux->prox->dado > valor)
        {
            break;
        }
    }

    L->tamanho++;
    if (aux == L->cabeca) // inicio
    {
        novo->prox = L->cabeca;
        L->cabeca = novo;
    }
    else if (aux->prox != NULL) // meio
    {
        novo->prox = aux->prox;
        aux->prox = novo;
    }
    else // fim
    {
        L->cauda->prox = novo;
        L->cauda = novo;
    }
}
