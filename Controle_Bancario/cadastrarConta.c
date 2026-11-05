/*  AUTOR.....: Matheus Henrique Lopes da Silva
    DATA......: 31/10/2026

    GRUPO.....: Matheus Henrique RA: 439746-2026
                John Bryan RA: 437929-2026

    OBJETIVO..: Cadastrar uma nova conta bancaria, armazenando seus dados
*/




#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void cadastrarConta(void) {
    CONTA *nova;

    system("cls");

    nova = (CONTA *) malloc(sizeof(CONTA));

    if (nova == NULL) {
        printf("Erro ao alocar memoria!");
        return;
    }

    for (int x = 10; x <= 70; x++) {
        gotoxy(x, 3);
        printf("-");
        gotoxy(x, 22);
        printf("-");
    }

    for (int y = 3; y <= 22; y++) {
        gotoxy(10, y);
        printf("|");
        gotoxy(70, y);
        printf("|");
    }

    gotoxy(28, 5);
    printf("CADASTRO DE CONTA");

    gotoxy(12, 7);
    printf("Codigo da conta: ");
    scanf("%d", &nova->codigo);

    gotoxy(12, 9);
    printf("Banco: ");
    scanf(" %49[^\n]", nova->banco);

    gotoxy(12, 11);
    printf("Agencia: ");
    scanf("%d", &nova->agencia);

    gotoxy(12, 13);
    printf("Numero da conta: ");
    scanf("%d", &nova->numeroConta);

    gotoxy(12, 15);
    printf("Tipo da conta: ");
    scanf(" %29[^\n]", nova->tipo);

    gotoxy(12, 17);
    printf("Saldo inicial: ");
    scanf("%f", &nova->saldo);

    gotoxy(12, 19);
    printf("Limite: ");
    scanf("%f", &nova->limite);

    gotoxy(12, 21);
    printf("Status (1 - Ativa / 0 - Inativa): ");
    scanf("%d", &nova->status);

    nova->ant = NULL;
    nova->prox = NULL;

    inserirFinal(nova);

    gotoxy(20, 24);
    printf("CONTA CADASTRADA COM SUCESSO!");

    gotoxy(20, 26);
    printf("Pressione ENTER para continuar...");
    getchar();
    getchar();
}
