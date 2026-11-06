/*  AUTOR.....: Matheus Henrique Lopes da Silva
    DATA......: 05/11/2026

    GRUPO.....: Matheus Henrique RA: 439746-2026
                John Bryan RA: 437929-2026

    OBJETIVO..: Exclusão de contas
*/

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void excluirConta(void) {
    CONTA *aux;
    int codigo;
    char confirmar;

    system("cls");

    gotoxy(10, 3);
    printf("------------------------------------------------");

    gotoxy(10, 4);
    printf("|                 EXCLUIR CONTA                |");

    gotoxy(10, 5);
    printf("------------------------------------------------");

    if (inicio == NULL) {
        gotoxy(15, 10);
        printf("Nenhuma conta cadastrada!");

        gotoxy(15, 13);
        printf("Pressione ENTER para continuar...");
        getchar();
        getchar();
        return;
    }

    gotoxy(12, 8);
    printf("Digite o codigo da conta: ");
    scanf("%d", &codigo);

    aux = inicio;

    // Procura a conta pelo codigo
    while (aux != NULL && aux->codigo != codigo) {
        aux = aux->prox;
    }

    // Verifica se a conta foi encontrada
    if (aux == NULL) {
        gotoxy(15, 12);
        printf("Conta nao encontrada!");

        gotoxy(15, 15);
        printf("Pressione ENTER para continuar...");
        getchar();
        getchar();
        return;
    }

    // Exibe os dados da conta encontrada
    gotoxy(12, 10);
    printf("Conta encontrada!");

    gotoxy(12, 11);
    printf("Banco: %s", aux->banco);

    gotoxy(12, 12);
    printf("Agencia: %d", aux->agencia);

    gotoxy(12, 13);
    printf("Numero da conta: %d", aux->numeroConta);

    gotoxy(12, 14);
    printf("Saldo: R$ %.2f", aux->saldo);

    gotoxy(12, 16);
    printf("Deseja realmente excluir? (S/N): ");
    scanf(" %c", &confirmar);

    if (confirmar == 'S' || confirmar == 's') {

        // Caso 1: Exclusao da primeira conta
        if (aux->ant == NULL) {
            inicio = aux->prox;
        } 
        else {
            aux->ant->prox = aux->prox;
        }

        // Caso 2: Exclusao de uma conta do meio ou final
        if (aux->prox != NULL) {
            aux->prox->ant = aux->ant;
        }

        // Libera a memoria da conta
        free(aux);

        gotoxy(15, 19);
        printf("Conta excluida com sucesso!");

    } 
    else {
        gotoxy(15, 19);
        printf("Exclusao cancelada!");
    }

    gotoxy(15, 22);
    printf("Pressione ENTER para continuar...");

    getchar();
    getchar();
}
