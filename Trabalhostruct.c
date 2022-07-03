#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;


struct lista
{
    char matricula[20];
    char nome[40];
    Data nascimento;
    float media;
    struct lista *next, *anterior;
};
typedef struct lista Lista;

struct lista *inicio;
struct lista *fim;

Lista *ptUltimo(Lista *elemento)
{
    Lista *aux = elemento;
    for (aux = elemento; aux->next != NULL; aux = aux->next)
        ;
    return aux;
}

// inserir dados na lista
Lista *inserirDados(Lista *first)
{
    Lista *Dado = malloc(sizeof(Lista));
    Lista *aux;

    scanf("%s", Dado->matricula);
    scanf("%s", Dado->nome);
    scanf("%d/%d/%d", &Dado->nascimento.dia, &Dado->nascimento.mes, &Dado->nascimento.ano);
    scanf("%f", &Dado->media);
    Dado->next = NULL;

    if (first == NULL)
    {
        first = Dado;
        // aux = Dado;
    }
    else
    {
        aux = ptUltimo(first);
        aux->next = Dado;
    }
    return first;
}

// remover elemento da lista
Lista *remover(Lista *first, char matri[20])
{
    Lista *aux, *anterior = NULL;
    aux = first;

    while (aux != NULL)
    {
        if ((strcmp(aux->matricula, matri)) == 0)
        {
            if (aux == first)
            {
                first = aux->next;
            }
            else
            {

                anterior->next = anterior->next->next;
            }
            free(aux);
        }
        anterior = aux;

        aux = aux->next;
    }
    return first;
}
// ennumerar quantos elementos na lista
int conta(Lista *first)
{
    int contador = 0;
    Lista *aux;

    for (aux = first; aux != NULL; aux = aux->next)
    {
        contador += 1;
    }
    return contador;
}
// lista a listar a lista
void imprimir(Lista *first)
{
    Lista *aux;

    for (aux = first; aux != NULL; aux = aux->next)
    {
        printf("%s, %s, %d/%d/%d, %.2f\n", aux->matricula, aux->nome, aux->nascimento.dia, aux->nascimento.mes, aux->nascimento.ano, aux->media);
    }
}

void sair( Lista *first){

    Lista * aux; 

    while(first != NULL){
        aux = first->next;
        free(first);
        first = aux;
        printf("-");
    }
}

// função para inverter a lista 
void invertaLista(Lista *first)
{
    Lista *aux;
    aux = first;

    if (aux == NULL)
    {
        return;
    }
    else
    {
        invertaLista(aux->next);
        printf("%s, %s, %d/%d/%d, %.2f\n", aux->matricula, aux->nome, aux->nascimento.dia, aux->nascimento.mes, aux->nascimento.ano, aux->media);

        aux = aux->next;
    }
}


void menu(Lista *first)
{
    int x, cont;
    char matricula[20];

    while (x != 0)
    {
        // printf("1- inserir dados\n2-excluir dados\n3-Listar dados\n4-Listar inversa\n5-contar\n0-sair\n");
        scanf("%d", &x);

        if (x == 1)
        {
            // inserirDados(first);
            first = inserirDados(first);
        }
        else if (x == 2)
        {
            if (first == NULL)
            {
                printf("Lista Vazia!\n");
            }
            else
            {
                scanf("%s", matricula);
                first = remover(first, matricula);
            }
        }
        else if (x == 3)
        {
            if (first == NULL)
            {
                printf("Lista Vazia\n");
            }
            else
            {
                imprimir(first);
            }
        }else if (x == 4)
        {
            if (first == NULL)
            {
                printf("Lista Vazia!\n");
            }
            else
            {
                invertaLista(first);
            }
        }
        else if (x == 5)
        {
            if (first == NULL)
            {
                printf("Lista Vazia\n");
            }
            else
            {
                cont = conta(first);
                printf("%d\n", cont);
            }
        }
        
        else if (x == 0){
            sair(first);
            printf("\n");
        }
    }
}

int main()
{
    Lista *first = NULL;
    menu(first);

    // Lista *valor,*varial;

    // varial=inserirDados(first);

    // imprimir(varial);

    return 0;

   
}