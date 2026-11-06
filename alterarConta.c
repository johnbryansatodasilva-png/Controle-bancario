/*  AUTOR.....: Matheus Henrique Lopes da Silva
    DATA......: 31/10/2026

    GRUPO.....: Matheus Henrique RA: 439746-2026
                John Bryan RA: 437929-2026

    OBJETIVO..: Alteração de contas
*/

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void alterarConta(void) {
    CONTA *aux;
    int codigo;
    int opcao;

    system("cls");

    for (int x = 10; x <= 75; x++) {
        gotoxy(x, 3);
        printf("-");
        gotoxy(x, 30);
        printf("-");
    }

    for (int y = 3; y <= 30; y++) {
        gotoxy(10, y);
        printf("|");
        gotoxy(75, y);
        printf("|");
    }

    gotoxy(29, 5);
    printf("ALTERAR CONTA");

    gotoxy(12, 8);
    printf("Digite o codigo da conta: ");
    scanf("%d", &codigo);

    aux = inicio;

    while (aux != NULL && aux->codigo != codigo) {
        aux = aux->prox;
    }

    if (aux == NULL) {
        gotoxy(20, 14);
        printf("Conta nao encontrada!");
        gotoxy(20, 28);
        printf("Pressione ENTER para continuar...");
        getchar();
        getchar();
        return;
    }

    if (aux->status != 1) {
        gotoxy(20, 14);
        printf("Esta conta esta inativa!");
        gotoxy(20, 28);
        printf("Pressione ENTER para continuar...");
        getchar();
        getchar();
        return;
    }

    gotoxy(12, 10);
    printf("Conta encontrada!");

    gotoxy(12, 11);
    printf("Banco: %s", aux->banco);

    gotoxy(12, 12);
    printf("Agencia: %d", aux->agencia);

    gotoxy(12, 13);
    printf("Numero da conta: %d", aux->numeroConta);

    gotoxy(12, 14);
    printf("Tipo: %s", aux->tipo);

    gotoxy(12, 15);
    printf("Limite: %.2f", aux->limite);

    gotoxy(12, 17);
    printf("O que deseja alterar?");

    gotoxy(12, 18);
    printf("1 - Banco");

    gotoxy(12, 19);
    printf("2 - Agencia");

    gotoxy(12, 20);
    printf("3 - Numero da conta");

    gotoxy(12, 21);
    printf("4 - Tipo da conta");

    gotoxy(12, 22);
    printf("5 - Limite");

    gotoxy(12, 24);
    printf("Opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            gotoxy(12, 26);
            printf("Novo banco: ");
            scanf(" %49[^\n]", aux->banco);
            break;

        case 2:
            gotoxy(12, 26);
            printf("Nova agencia: ");
            scanf("%d", &aux->agencia);
            break;

        case 3:
            gotoxy(12, 26);
            printf("Novo numero da conta: ");
            scanf("%d", &aux->numeroConta);
            break;

        case 4:
            gotoxy(12, 26);
            printf("Novo tipo da conta: ");
            scanf(" %29[^\n]", aux->tipo);
            break;

        case 5:
            gotoxy(12, 26);
            printf("Novo limite: ");
            scanf("%f", &aux->limite);
            break;

        default:
            gotoxy(12, 26);
            printf("Opcao invalida!");
            break;
    }

    if (opcao >= 1 && opcao <= 5) {
        gotoxy(12, 28);
        printf("Dados alterados com sucesso!");
    }

    gotoxy(20, 32);
    printf("Pressione ENTER para continuar...");

    getchar();
    getchar();
}
