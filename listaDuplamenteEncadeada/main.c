#include "list.h"

#include <stdio.h>

int main()
{
    Lista *L = criar_Lista();

   /* inserir_inicio_lista(L, 7);
    inserir_inicio_lista(L, 4);
    inserir_inicio_lista(L, 2);
    inserir_inicio_lista(L, 10);

    Imprimir_Lista(L);

    Imprimir_Lista_Invertido(L);

    puts("Adicionando no final da Lista");
    inserir_final_lista(L, 10);
    inserir_final_lista(L, 2);
    inserir_final_lista(L, 4);
    inserir_final_lista(L, 7);

    Imprimir_Lista(L);

    Imprimir_Lista_Invertido(L); */

    inserir_final_lista(L, 4);
    inserir_final_lista(L, 7);
    inserir_inicio_lista(L, 2);
    inserir_inicio_lista(L, 10);

    Imprimir_Lista(L);

    destruir_Lista(&L);

    return 0;
}
