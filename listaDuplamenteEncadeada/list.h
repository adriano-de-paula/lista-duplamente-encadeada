#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct _no_duplo NoDuplo, No;
typedef struct _lista_dupla ListaDupla, Lista;

No *criar_No(int valor);

Lista *criar_Lista();
void destruir_Lista (Lista **referencia);
bool Lista_vazia(const Lista *L);
void inserir_inicio_lista(Lista *L, int valor);
void inserir_final_lista (Lista *L, int valor);
void Imprimir_Lista(const Lista *L);
void Imprimir_Lista_Invertido(const Lista *L);

void remover_Lista(Lista *L, int valor);

#endif // LIST_H
