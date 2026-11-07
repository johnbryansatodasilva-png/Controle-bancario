/*  AUTOR.....: Matheus Henrique Lopes da Silva
    DATA......: 07/11/2026

    GRUPO.....: Matheus Henrique RA: 439746-2026
                John Bryan RA: 437929-2026

    OBJETIVO..: Inserir uma nova conta em uma posicao especifica da lista encadeada, atualizando os ponteiros dos elementos
*/


#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void inserirPosicao(CONTA *nova, int posicao) {
    CONTA *aux;
    int contador = 1;

    if (nova == NULL) {
        return;
    }

    if (inicio == NULL || posicao <= 1) {
        nova->ant = NULL;
        nova->prox = inicio;

        if (inicio != NULL) {
            inicio->ant = nova;
        }

        inicio = nova;
        return;
    }

    aux = inicio;

    while (aux->prox != NULL && contador < posicao - 1) {
        aux = aux->prox;
        contador++;
    }

    nova->prox = aux->prox;
    nova->ant = aux;

    if (aux->prox != NULL) {
        aux->prox->ant = nova;
    }

    aux->prox = nova;
}
