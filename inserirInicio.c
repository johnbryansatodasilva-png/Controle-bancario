
/*  AUTOR.....: Matheus Henrique Lopes da Silva
    DATA......: 05/11/2026

    GRUPO.....: Matheus Henrique RA: 439746-2026
                John Bryan RA: 437929-2026

    OBJETIVO..: Inserir uma conta no inicio da lista.
*/

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void inserirInicio(CONTA *nova) {

    // Verifica se a lista esta vazia
    if (inicio == NULL) {

        inicio = nova;
        nova->ant = NULL;
        nova->prox = NULL;

    }
    else {


        nova->prox = inicio;
        nova->ant = NULL;


        inicio->ant = nova;


        inicio = nova;
    }
}
