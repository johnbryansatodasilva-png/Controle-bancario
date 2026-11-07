/*  AUTOR.....: Matheus Henrique Lopes da Silva
    DATA......: 06/11/2026

    GRUPO.....: Matheus Henrique RA: 439746-2026
                John Bryan RA: 437929-2026

    OBJETIVO..: Realizar a exclusao de contas, verificando se existem movimentacoes vinculadas antes de permitir a operacao
*/



#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void excluirConta(void) {
    CONTA *aux;
    MOVIMENTACAO *mov;
    int codigo;
    int opcao;

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
    printf("EXCLUIR CONTA");

    if (inicio == NULL) {
        gotoxy(20, 14);
        printf("Nenhuma conta cadastrada!");
        goto finalizar;
    }

    gotoxy(12, 9);
    printf("Digite o codigo da conta: ");
    scanf("%d", &codigo);

    aux = inicio;

    while (aux != NULL && aux->codigo != codigo) {
        aux = aux->prox;
    }

    if (aux == NULL) {
        gotoxy(20, 15);
        printf("Conta nao encontrada!");
        goto finalizar;
    }

    mov = inicioMov;

    while (mov != NULL) {
        if (mov->codigoConta == codigo) {
            gotoxy(12, 14);
            printf("Esta conta possui movimentacoes!");

            gotoxy(12, 16);
            printf("A exclusao nao pode ser realizada.");

            goto finalizar;
        }

        mov = mov->prox;
    }

    gotoxy(12, 12);
    printf("Conta encontrada!");

    gotoxy(12, 14);
    printf("Banco: %s", aux->banco);

    gotoxy(12, 15);
    printf("Numero da conta: %d", aux->numeroConta);

    gotoxy(12, 16);
    printf("Saldo: R$ %.2f", aux->saldo);

    gotoxy(12, 19);
    printf("Confirmar exclusao? (1 - Sim / 0 - Nao): ");

    scanf("%d", &opcao);

    if (opcao == 1) {

        if (aux->ant == NULL) {
            inicio = aux->prox;
        } else {
            aux->ant->prox = aux->prox;
        }

        if (aux->prox != NULL) {
            aux->prox->ant = aux->ant;
        }

        free(aux);

        gotoxy(20, 22);
        printf("Conta excluida com sucesso!");

    } else {
        gotoxy(20, 22);
        printf("Exclusao cancelada!");
    }

finalizar:

    gotoxy(20, 27);
    printf("Pressione ENTER para continuar...");
    getchar();
    getchar();
}
