/*  AUTOR.....: Matheus Henrique Lopes da Silva
    DATA......: 01/11/2026

    GRUPO.....: Matheus Henrique RA: 439746-2026
                John Bryan RA: 437929-2026

    OBJETIVO..: Inserir uma nova conta no final da lista de contas cadastradas
*/


#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void inserirFinal(CONTA *nova) {

    if (inicio == NULL) {
        inicio = nova;
    }
    else {
        CONTA *aux = inicio;

        while (aux->prox != NULL) {
            aux = aux->prox;
        }

        aux->prox = nova;
        nova->ant = aux;
    }
}
