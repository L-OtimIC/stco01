#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <vector>
#include <list>

#define MAX 1000000

struct LArray{
    int data[MAX];
    int n;
};

void inicializa_LArray(LArray* lista) { lista->n = 0; }

struct No {
    int data;
    No* prox;
};

No* criar_no_simples(int valor){
    No* novo = (No*) malloc(sizeof(No));
    novo->data = valor;
    novo->prox = NULL;
    return novo;
}

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
    No *head, *tail;
    // NoDuplo *head, *tail;
};

void inicializa_LLigada(LLigada* lista){
    lista->head = lista->tail = NULL;
}

void insere_inicio(LArray* lista, int valor)
{
    if (lista->n == MAX)
        return;
    for(int i = lista->n; i > 0; --i)
        lista->data[i] = lista->data[i - 1];
    lista->data[0] = valor;
    lista->n++;
}

void insere_inicio(LLigada* lista, int valor)
{
    No* novo = criar_no_simples(valor);
    if (lista->head != NULL)
        novo->prox = lista->head;
    else
        lista->tail = novo;
    lista->head = novo;
}

int main()
{
    clock_t inicio = clock();

    LArray lista;
    inicializa_LArray(&lista);

    // for(int i = 0; i < MAX/2; ++i)
    //     insere_inicio(&lista, i);

    clock_t fim = clock();
    double tempo = ((double) fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo decorrido (LArray): %lf\n", tempo);

    inicio = clock();
    LLigada lista_ligada;
    inicializa_LLigada(&lista_ligada);

    for(int i = 0; i < MAX/2; ++i)
        insere_inicio(&lista_ligada, i);

    fim = clock();
    tempo = ((double) fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo decorrido (LLigada): %lf\n", tempo);

    inicio = clock();
    std::vector<int> v;
    for(int i = 0; i < MAX/2; ++i)
        v.insert(v.begin(), i);

    fim = clock();
    tempo = ((double) fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo decorrido (std::vector): %lf\n", tempo);

    inicio = clock();
    std::list<int> l;
    for(int i = 0; i < MAX/2; ++i)
        l.emplace(l.begin(), i);

    fim = clock();
    tempo = ((double) fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo decorrido (std::list): %lf\n", tempo);

    return 0;
}