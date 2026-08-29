#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct dado {
    char msg[500];
    char autor[50];
    clock_t horario;
};

struct NoDuplo {
    dado data;
    NoDuplo* prox;
    NoDuplo* ant;
};

NoDuplo* criar_no_duplo(char* msg, char* autor, clock_t hora)
{
    NoDuplo* novo = (NoDuplo*) malloc(sizeof(NoDuplo));
    strcpy(novo->data.msg, msg);
    strcpy(novo->data.autor, autor);
    novo->data.horario = hora;
    novo->prox = novo->ant = NULL;
    return novo;
}

struct LLigada{
    NoDuplo *head, *tail;
};

void inicializa_LLigada(LLigada* lista){
    lista->head = lista->tail = NULL;
}

void insere(LLigada* lista, char* msg, char* autor)
{
    NoDuplo* novo = criar_no_duplo(msg, autor, clock());

    if (lista->head == NULL)
    {
        lista->head = lista->tail = novo;
        return;
    }

    lista->tail->prox = novo;
    novo->ant = lista->tail;
    lista->tail = novo;
}

dado remover(LLigada* lista, NoDuplo* pos)
{
    auto valor = pos->data;
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

NoDuplo* buscar(LLigada* lista, char* msg = NULL, char* autor = NULL)
{
    for (auto it = lista->head; it != NULL; it = it->prox)
    {
        if (msg != NULL && strcmp(it->data.msg, msg) == 0)
            return it;
        if (autor != NULL && strcmp(it->data.autor, autor) == 0)
            return it;
    }
    return NULL;
}


int main()
{
    // 0 - sair, 1 - inserir msg, 2 - carregar msg, 3 - buscar msg, 4 - excluir msg
    int opcao, n;
    char msg[500], autor[50];
    LLigada lista;
    inicializa_LLigada(&lista);

    clock_t inicio = clock();

    while(true)
    {
        printf("Digite a opcao: ");
        scanf("%d", &opcao);

        if (opcao == 0)
            break;

        if (opcao == 1)
        {
            // fgets(msg, 499, stdin);
            printf("Digite a msg: ");
            getchar();
            scanf("%499[^\n]", msg);

            // fgets(autor, 49, stdin);
            getchar();
            printf("Digite o autor: ");
            scanf("%49[^\n]", autor);
            insere(&lista, msg, autor);
        }

        if (opcao == 2)
        {
            scanf("%d", &n);
            int i = 1;
            for (auto it = lista.head; it != NULL && i <= n; it = it->prox, ++i)
            {
                printf("%lf : %s - %s\n",
                    ((double) (it->data.horario - inicio)) / CLOCKS_PER_SEC,
                    it->data.autor,
                    it->data.msg);
            }
        }

        if (opcao == 3)
        {
            // 0 - msg, 1 - autor
            int escolha;
            scanf("%d", &escolha);
            if (escolha == 0)
            {
                getchar();
                scanf("%499[^\n]", msg);
                printf("Buscando %s...\n", msg);
                auto res = buscar(&lista, msg);

                if (res != NULL)
                {
                    printf("%lf : %s - %s\n",
                        ((double) (res->data.horario - inicio)) / CLOCKS_PER_SEC,
                        res->data.autor,
                        res->data.msg);
                }
            }
            if (escolha == 1)
            {
                getchar();
                scanf("%49[^\n]", autor);
                printf("Buscando %s...\n", autor);
                auto res = buscar(&lista, NULL, autor);

                if (res != NULL)
                {
                    printf("%lf : %s - %s\n",
                        ((double) (res->data.horario - inicio)) / CLOCKS_PER_SEC,
                        res->data.autor,
                        res->data.msg);
                }
            }
        }

        if (opcao == 4)
        {
            // 0 - msg, 1 - autor
            int escolha;
            scanf("%d", &escolha);
            NoDuplo* res;
            if (escolha == 0)
            {
                getchar();
                scanf("%499[^\n]", msg);
                fgets(msg, 499, stdin);
                res = buscar(&lista, msg);
            }
            if (escolha == 1)
            {
                getchar();
                scanf("%49[^\n]", autor);
                res = buscar(&lista, NULL, autor);
            }
            if (res != NULL)
            {
                printf("Removendo... %lf : %s - %s\n",
                    ((double) (res->data.horario - inicio)) / CLOCKS_PER_SEC,
                    res->data.autor,
                    res->data.msg);
            }
            remover(&lista, res);
        }
    }


    return 0;
}