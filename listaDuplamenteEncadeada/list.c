#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _no_duplo {
    int valor;
    struct _no_duplo *anterior;
    struct _no_duplo *proximo;
} NoDuplo, No;

typedef struct _lista_dupla {
    NoDuplo *inicio;
    NoDuplo *fim;
    size_t tamanho;
} ListaDupla, Lista;

No *criar_No(int valor){
    No *no = (No*) calloc (1, sizeof (No));
    no->anterior = NULL;
    no->proximo = NULL;
    no->valor = valor;

    return no;
}

Lista *criar_Lista(){
    Lista *L = (Lista*) calloc (1, sizeof(Lista));
    L->inicio = NULL;
    L->fim = NULL;
    L->tamanho = 0;

    return L;
}


void destruir_Lista (Lista **referencia){
    Lista *L = *referencia;

    No *p = L->inicio;
    No *auxiliar = NULL;

    while (p != NULL){
        auxiliar = p;
        p = p->proximo;
        free(auxiliar);
    }
    free(L);

    *referencia = NULL;
}

bool Lista_vazia(const Lista *L){
     return L->tamanho == 0;
}

void inserir_inicio_lista(Lista *L, int valor){
    No *p = criar_No(valor);
    p->proximo = L->inicio;

    if (Lista_vazia(L)){
        L->fim = p;
    }
    else {
       L->inicio->anterior = p;
    }

    L->inicio = p;
    L->tamanho++;
}

void inserir_final_lista (Lista *L, int valor){
    No *p = criar_No (valor);

    if (Lista_vazia(L)){
        L->inicio = p;
    }
    else {
        L->fim->proximo = p;
        p->anterior = L->fim;
    }

    L->fim = p;
    L->tamanho++;
}

void Imprimir_Lista(const Lista *L){
    No *p = L->inicio;

    printf("L -> ");

    while(p != NULL){
        printf("%d -> ", p->valor);
        p = p->proximo;
    }

    printf("NULL\n");

    if (L->fim == NULL){
        printf("L->fim = NULL\n");
    }
    else {
        printf("L->fim = %d\n", L->fim->valor);
    }

    printf("Tamanho: %lu\n", L->tamanho);
    puts("");
}


void Imprimir_Lista_Invertido(const Lista *L){
    No *p = L->fim;

    printf("L -> fim -> ");

    while(p != NULL){
        printf("%d -> ", p->valor);
        p = p->anterior;
    }

    printf("NULL\n");

    if (L->fim == NULL){
        printf("L->inicio = NULL\n");
    }
    else {
        printf("L->inicio = %d\n", L->fim->valor);
    }

    printf("Tamanho: %lu\n", L->tamanho);
    puts("");
}

void remover_Lista(Lista *L, int valor){
    if(!Lista_vazia(L)){
        // CASO 1 : O ELEMENTO ESTÁ NA CABEÇA DA LISTA
        if (L->inicio->valor == valor){
                No *p = L->inicio;
                L->inicio = p->proximo;

                //A LISTA POSSUI APENAS UM ÚNICO ELEMENTO
                if (L->fim == p){ //(L->inicio == L->fim)
                   // L->inicio = NULL;
                    L->fim = NULL;
                }
                //A LISTA POSSUI MAIS DE UM ELEMENTO
                else{
                  //  L->inicio = p->proximo;
                    L->inicio->anterior = NULL;
                }

                free(p);
                L->tamanho--;
        }
        //CASO 2 : ELEMENTO NO MEIO DA LISTA
        //CASO 3 : ELEMENTO NO FINAL DA LISTA
        else {
            No *p = L->inicio->proximo;
        }
    }
}

