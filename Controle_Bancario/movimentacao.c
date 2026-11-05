/*  AUTOR.....: Matheus Henrique Lopes da Silva
    DATA......: 05/11/2026

    GRUPO.....: Matheus Henrique RA: 439746-2026
                John Bryan RA: 437929-2026

    OBJETIVO..: Exibir as opcoes de registro e consulta de movimentacoes bancarias
*/


#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void registrarMovimento(void) {
    int codigo;
    int maiorNumero = 0;
    int opcao;
    float valor;

    CONTA *conta = inicio;
    MOVIMENTACAO *nova;
    MOVIMENTACAO *aux;

    system("cls");

    for (int x = 10; x <= 75; x++) {
        gotoxy(x, 3);
        printf("-");
        gotoxy(x, 28);
        printf("-");
    }

    for (int y = 3; y <= 28; y++) {
        gotoxy(10, y);
        printf("|");
        gotoxy(75, y);
        printf("|");
    }

    gotoxy(27, 5);
    printf("REGISTRAR MOVIMENTACAO");

    if (inicio == NULL) {
        gotoxy(20, 14);
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
        gotoxy(20, 14);
        printf("Conta nao encontrada!");
        goto finalizar;
    }

    if (conta->status != 1) {
        gotoxy(20, 14);
        printf("Esta conta esta inativa!");
        goto finalizar;
    }

    gotoxy(12, 10);
    printf("Conta encontrada!");

    gotoxy(12, 11);
    printf("Banco: %s", conta->banco);

    gotoxy(12, 12);
    printf("Saldo atual: R$ %.2f", conta->saldo);

    gotoxy(12, 14);
    printf("1 - Deposito");

    gotoxy(12, 15);
    printf("2 - Saque");

    gotoxy(12, 17);
    printf("Escolha: ");
    scanf("%d", &opcao);

    if (opcao != 1 && opcao != 2) {
        gotoxy(12, 19);
        printf("Opcao invalida!");
        goto finalizar;
    }

    gotoxy(12, 19);
    printf("Valor da movimentacao: R$ ");
    scanf("%f", &valor);

    if (valor <= 0) {
        gotoxy(12, 21);
        printf("Valor invalido!");
        goto finalizar;
    }

    if (opcao == 2 && valor > conta->saldo + conta->limite) {
        gotoxy(12, 21);
        printf("Saldo e limite insuficientes!");
        goto finalizar;
    }

    nova = (MOVIMENTACAO *) malloc(sizeof(MOVIMENTACAO));

    if (nova == NULL) {
        gotoxy(12, 21);
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

    if (opcao == 1) {
        conta->saldo += valor;
        snprintf(nova->tipo, sizeof(nova->tipo), "Deposito");
    } else {
        conta->saldo -= valor;
        snprintf(nova->tipo, sizeof(nova->tipo), "Saque");
    }

    gotoxy(12, 21);
    printf("Data (DD/MM/AAAA): ");
    scanf(" %10s", nova->data);

    nova->saldoAtual = conta->saldo;
    nova->prox = NULL;

    if (inicioMov == NULL) {
        inicioMov = nova;
    } else {
        aux = inicioMov;

        while (aux->prox != NULL) {
            aux = aux->prox;
        }

        aux->prox = nova;
    }

    gotoxy(12, 24);
    printf("Movimentacao registrada com sucesso!");

    gotoxy(12, 25);
    printf("Novo saldo: R$ %.2f", conta->saldo);

finalizar:
    gotoxy(20, 30);
    printf("Pressione ENTER para continuar...");
    getchar();
    getchar();
}


void consultarMovimento(void) {
    MOVIMENTACAO *aux = inicioMov;
    int codigo;
    int linha = 11;
    int encontrou = 0;

    system("cls");

    for (int x = 10; x <= 75; x++) {
        gotoxy(x, 3);
        printf("-");
        gotoxy(x, 28);
        printf("-");
    }

    for (int y = 3; y <= 28; y++) {
        gotoxy(10, y);
        printf("|");
        gotoxy(75, y);
        printf("|");
    }

    gotoxy(25, 5);
    printf("CONSULTA DE MOVIMENTACOES");

    if (inicioMov == NULL) {
        gotoxy(20, 14);
        printf("Nenhuma movimentacao cadastrada!");
        goto finalizarConsulta;
    }

    gotoxy(12, 8);
    printf("Codigo da conta: ");
    scanf("%d", &codigo);

    while (aux != NULL) {
        if (aux->codigoConta == codigo) {

            if (linha > 21) {
                gotoxy(12, 24);
                printf("Existem mais movimentacoes...");
                break;
            }

            encontrou = 1;

            gotoxy(12, linha++);
            printf("Numero: %d", aux->numero);

            gotoxy(12, linha++);
            printf("Conta: %d", aux->codigoConta);

            gotoxy(12, linha++);
            printf("Data: %s", aux->data);

            gotoxy(12, linha++);
            printf("Tipo: %s", aux->tipo);

            gotoxy(12, linha++);
            printf("Valor: R$ %.2f", aux->valor);

            gotoxy(12, linha++);
            printf("Saldo apos movimentacao: R$ %.2f",
                   aux->saldoAtual);

            linha++;
        }

        aux = aux->prox;
    }

    if (!encontrou) {
        gotoxy(20, 14);
        printf("Nenhuma movimentacao encontrada!");
    }

finalizarConsulta:
    gotoxy(20, 30);
    printf("Pressione ENTER para continuar...");
    getchar();
    getchar();
}


void menuMovimentacao(void) {
    int opcao;

    do {
        system("cls");

        for (int x = 10; x <= 70; x++) {
            gotoxy(x, 3);
            printf("-");
            gotoxy(x, 15);
            printf("-");
        }

        for (int y = 3; y <= 15; y++) {
            gotoxy(10, y);
            printf("|");
            gotoxy(70, y);
            printf("|");
        }

        gotoxy(24, 5);
        printf("MOVIMENTACOES BANCARIAS");

        gotoxy(15, 7);
        printf("1 - Registrar movimentacao");

        gotoxy(15, 9);
        printf("2 - Consultar movimentacoes");

        gotoxy(15, 11);
        printf("0 - Voltar");

        gotoxy(15, 13);
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                registrarMovimento();
                break;

            case 2:
                consultarMovimento();
                break;

            case 0:
                break;

            default:
                gotoxy(15, 14);
                printf("Opcao invalida!");
                gotoxy(15, 17);
                printf("Pressione ENTER para continuar...");
                getchar();
                getchar();
        }

    } while (opcao != 0);
}
