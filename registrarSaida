
/*  AUTOR.....: Matheus Henrique Lopes da Silva
    DATA......: 05/11/2026

    GRUPO.....: Matheus Henrique RA: 439746-2026
                John Bryan RA: 437929-2026

    OBJETIVO..: Registrar uma saida de dinheiro da conta.
*/

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void registrarSaida(void) {

    int codigo;
    int maiorNumero = 0;
    float valor;

    CONTA *conta = inicio;
    MOVIMENTACAO *nova;
    MOVIMENTACAO *aux;

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


    gotoxy(27, 5);
    printf("REGISTRAR SAIDA");


    if (inicio == NULL) {
        gotoxy(15, 12);
        printf("Nenhuma conta cadastrada!");
        goto finalizar;
    }


    gotoxy(12, 8);
    printf("Codigo da conta: ");
    scanf("%d", &codigo);


    while (conta != NULL && conta->codigo != codigo) {
        conta = conta->prox;
    }

    if (conta == NULL) {
        gotoxy(15, 12);
        printf("Conta nao encontrada!");
        goto finalizar;
    }


    if (conta->status != 1) {
        gotoxy(15, 12);
        printf("Esta conta esta inativa!");
        goto finalizar;
    }


    gotoxy(12, 10);
    printf("Conta encontrada!");

    gotoxy(12, 11);
    printf("Banco: %s", conta->banco);

    gotoxy(12, 12);
    printf("Saldo atual: R$ %.2f", conta->saldo);

    gotoxy(12, 13);
    printf("Limite: R$ %.2f", conta->limite);


    gotoxy(12, 16);
    printf("Valor da saida: R$ ");
    scanf("%f", &valor);


    if (valor <= 0) {
        gotoxy(12, 19);
        printf("Valor invalido!");
        goto finalizar;
    }


    if (valor > conta->saldo + conta->limite) {
        gotoxy(12, 19);
        printf("Saldo e limite insuficientes!");
        goto finalizar;
    }


    nova = (MOVIMENTACAO *) malloc(sizeof(MOVIMENTACAO));

    if (nova == NULL) {
        gotoxy(12, 19);
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


    nova->numero = maiorNumero + 1;
    nova->codigoConta = codigo;
    nova->valor = valor;

    snprintf(nova->tipo, sizeof(nova->tipo), "Saque");


    gotoxy(12, 18);
    printf("Data (DD/MM/AAAA): ");
    scanf(" %10s", nova->data);


    conta->saldo -= valor;

    nova->saldoAtual = conta->saldo;
    nova->prox = NULL;


    if (inicioMov == NULL) {
        inicioMov = nova;
    }
    else {
        aux = inicioMov;

        while (aux->prox != NULL) {
            aux = aux->prox;
        }

        aux->prox = nova;
    }

 
    gotoxy(12, 22);
    printf("SAIDA REGISTRADA COM SUCESSO!");

    gotoxy(12, 24);
    printf("Novo saldo: R$ %.2f", conta->saldo);

finalizar:

    gotoxy(15, 26);
    printf("Pressione ENTER para continuar...");

    getchar();
    getchar();
}
