/*  AUTOR.....: Matheus Henrique Lopes da Silva
    DATA......: 04/11/2026

    GRUPO.....: Matheus Henrique RA: 439746-2026
                John Bryan RA: 437929-2026

    OBJETIVO..: Consultar contas
    */



#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void consultarConta(void) {
    CONTA *aux = inicio;
    int linha = 6;

    system("cls");

    for (int x = 10; x <= 75; x++) {
        gotoxy(x, 3);
        printf("-");
        gotoxy(x, 25);
        printf("-");
    }

    for (int y = 3; y <= 25; y++) {
        gotoxy(10, y);
        printf("|");
        gotoxy(75, y);
        printf("|");
    }

    gotoxy(29, 5);
    printf("CONSULTA DE CONTAS");

    if (inicio == NULL) {
        gotoxy(22, 14);
        printf("Nenhuma conta cadastrada!");

        gotoxy(22, 27);
        printf("Pressione ENTER para continuar...");
        getchar();
        getchar();
        return;
    }

    while (aux != NULL) {
        if (linha > 21) {
            gotoxy(12, 23);
            printf("Existem mais contas cadastradas...");
            break;
        }

        gotoxy(12, linha++);
        printf("Codigo: %d", aux->codigo);

        gotoxy(12, linha++);
        printf("Banco: %s", aux->banco);

        gotoxy(12, linha++);
        printf("Agencia: %d", aux->agencia);

        gotoxy(12, linha++);
        printf("Numero da conta: %d", aux->numeroConta);

        gotoxy(12, linha++);
        printf("Tipo: %s", aux->tipo);

        gotoxy(12, linha++);
        printf("Saldo: R$ %.2f", aux->saldo);

        gotoxy(12, linha++);
        printf("Limite: R$ %.2f", aux->limite);

        gotoxy(12, linha++);
        if (aux->status == 1) {
            printf("Status: Ativa");
        } else {
            printf("Status: Inativa");
        }

        aux = aux->prox;

        linha++;

        if (aux != NULL) {
            gotoxy(12, linha++);
            printf("-----------------------------------------------");
            linha++;
        }
    }

    gotoxy(20, 27);
    printf("Pressione ENTER para continuar...");
    getchar();
    getchar();
}
