/*  AUTOR.....: Matheus Henrique Lopes da Silva
    DATA......: 04/11/2026

    GRUPO.....: Matheus Henrique RA: 439746-2026
                John Bryan RA: 437929-2026

    OBJETIVO..: Consultar e exibir os dados das contas cadastradas
*/



#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void consultarConta(void) {
    CONTA *aux = inicio;
    int linha = 8;

    system("cls");

    for (int x = 5; x <= 80; x++) {
        gotoxy(x, 3);
        printf("-");
        gotoxy(x, 25);
        printf("-");
    }

    for (int y = 3; y <= 25; y++) {
        gotoxy(5, y);
        printf("|");
        gotoxy(80, y);
        printf("|");
    }

    gotoxy(32, 5);
    printf("CONSULTA DE CONTAS");

    if (inicio == NULL) {
        gotoxy(27, 14);
        printf("Nenhuma conta cadastrada!");
    }
    else {
        gotoxy(7, 7);
        printf("CODIGO  BANCO          AGENCIA  CONTA    TIPO       SALDO");

        gotoxy(7, 8);
        printf("---------------------------------------------------------------------");

        while (aux != NULL && linha <= 23) {

            gotoxy(7, linha++);
            printf("%-7d %-14.14s %-8d %-8d %-10.10s R$ %.2f",
                   aux->codigo,
                   aux->banco,
                   aux->agencia,
                   aux->numeroConta,
                   aux->tipo,
                   aux->saldo);

            aux = aux->prox;
        }

        if (aux != NULL) {
            gotoxy(20, 24);
            printf("Existem mais contas cadastradas...");
        }
    }

    gotoxy(25, 27);
    printf("Pressione ENTER para continuar...");
    getchar();
    getchar();
}