/*  AUTOR.....: John Bryan Sato da Silva
    DATA......: 06/11/2026

    GRUPO.....: Matheus Henrique RA: 439746-2026
                John Bryan RA: 437929-2026

    OBJETIVO..: Registrar uma saida de dinheiro da conta.
*/

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void transferencia(void) {

    int codigoOrigem, codigoDestino;
    int maiorNumero = 0;
    float valor;

    CONTA *origem = inicio;
    CONTA *destino = inicio;

    MOVIMENTACAO *saida;
    MOVIMENTACAO *entrada;
    MOVIMENTACAO *aux;

    char data[11];

    system("cls");

    for (int x = 10; x <= 70; x++) {
        gotoxy(x, 3);
        printf("-");
        gotoxy(x, 28);
        printf("-");
    }

    for (int y = 3; y <= 28; y++) {
        gotoxy(10, y);
        printf("|");
        gotoxy(70, y);
        printf("|");
    }

    gotoxy(25, 5);
    printf("TRANSFERENCIA BANCARIA");

    if (inicio == NULL) {
        gotoxy(15, 12);
        printf("Nenhuma conta cadastrada!");
        goto finalizar;
    }

    gotoxy(12, 8);
    printf("Codigo da conta de origem: ");
    scanf("%d", &codigoOrigem);

    while (origem != NULL && origem->codigo != codigoOrigem) {
        origem = origem->prox;
    }

    if (origem == NULL) {
        gotoxy(12, 11);
        printf("Conta de origem nao encontrada!");
        goto finalizar;
    }

    if (origem->status != 1) {
        gotoxy(12, 11);
        printf("Conta de origem inativa!");
        goto finalizar;
    }

    gotoxy(12, 10);
    printf("Saldo de origem: R$ %.2f", origem->saldo);

    gotoxy(12, 13);
    printf("Codigo da conta de destino: ");
    scanf("%d", &codigoDestino);

    if (codigoOrigem == codigoDestino) {
        gotoxy(12, 16);
        printf("As contas devem ser diferentes!");
        goto finalizar;
    }

    while (destino != NULL && destino->codigo != codigoDestino) {
        destino = destino->prox;
    }

    if (destino == NULL) {
        gotoxy(12, 16);
        printf("Conta de destino nao encontrada!");
        goto finalizar;
    }

    if (destino->status != 1) {
        gotoxy(12, 16);
        printf("Conta de destino inativa!");
        goto finalizar;
    }

    gotoxy(12, 15);
    printf("Saldo de destino: R$ %.2f", destino->saldo);

    gotoxy(12, 18);
    printf("Valor da transferencia: R$ ");
    scanf("%f", &valor);

    if (valor <= 0) {
        gotoxy(12, 20);
        printf("Valor invalido!");
        goto finalizar;
    }

    if (valor > origem->saldo + origem->limite) {
        gotoxy(12, 20);
        printf("Saldo e limite insuficientes!");
        goto finalizar;
    }

    gotoxy(12, 21);
    printf("Data (DD/MM/AAAA): ");
    scanf(" %10s", data);

    saida = malloc(sizeof(MOVIMENTACAO));
    entrada = malloc(sizeof(MOVIMENTACAO));

    if (saida == NULL || entrada == NULL) {
        free(saida);
        free(entrada);

        gotoxy(12, 23);
        printf("Erro ao alocar memoria!");
        goto finalizar;
    }

    aux = inicioMov;

    while (aux != NULL) {
        if (aux->numero > maiorNumero) {
            maiorNumero = aux->numero;
        }

        aux = aux->prox;
    }

    saida->numero = maiorNumero + 1;
    saida->codigoConta = codigoOrigem;
    saida->valor = valor;
    snprintf(saida->tipo, sizeof(saida->tipo), "Transf. Saida");
    snprintf(saida->data, sizeof(saida->data), "%s", data);

    entrada->numero = maiorNumero + 2;
    entrada->codigoConta = codigoDestino;
    entrada->valor = valor;
    snprintf(entrada->tipo, sizeof(entrada->tipo), "Transf. Entrada");
    snprintf(entrada->data, sizeof(entrada->data), "%s", data);

    origem->saldo -= valor;
    destino->saldo += valor;

    saida->saldoAtual = origem->saldo;
    entrada->saldoAtual = destino->saldo;

    saida->prox = entrada;
    entrada->prox = NULL;

    if (inicioMov == NULL) {
        inicioMov = saida;
    }
    else {
        aux = inicioMov;

        while (aux->prox != NULL) {
            aux = aux->prox;
        }

        aux->prox = saida;
    }

    gotoxy(12, 23);
    printf("TRANSFERENCIA REALIZADA COM SUCESSO!");

    gotoxy(12, 24);
    printf("Saldo de origem: R$ %.2f", origem->saldo);

    gotoxy(12, 25);
    printf("Saldo de destino: R$ %.2f", destino->saldo);

finalizar:

    gotoxy(15, 27);
    printf("Pressione ENTER para continuar...");

    getchar();
    getchar();
}
