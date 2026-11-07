/*  AUTOR.....: Matheus Henrique Lopes da Silva
    DATA......: 05/11/2026

    GRUPO.....: Matheus Henrique RA: 439746-2026
                John Bryan RA: 437929-2026

    OBJETIVO..: Registrar entradas e saidas financeiras, atualizar saldos e consultar o historico de movimentacoes
*/



#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

static int converterData(const char data[]) {
    int dia, mes, ano;
    char extra;

    if (sscanf(data, "%2d/%2d/%4d%c",
               &dia, &mes, &ano, &extra) != 3) {
        return 0;
    }

    if (ano < 1 || mes < 1 || mes > 12 || dia < 1) {
        return 0;
    }

    int diasMes[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if ((ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0)) {
        diasMes[1] = 29;
    }

    if (dia > diasMes[mes - 1]) {
        return 0;
    }

    return ano * 10000 + mes * 100 + dia;
}

static void registrarMovimentoTipo(int opcao) {
    int codigo;
    int maiorNumero = 0;
    int dataInformada;
    int ultimaData = 0;
    float valor;

    CONTA *conta = inicio;
    MOVIMENTACAO *nova;
    MOVIMENTACAO *aux;

    char data[11];

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
    printf("%s", opcao == 1 ? "REGISTRAR ENTRADA" : "REGISTRAR SAIDA");

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

    gotoxy(12, 16);
    printf("Data (DD/MM/AAAA): ");
    scanf("%10s", data);

    dataInformada = converterData(data);

    if (dataInformada == 0) {
        gotoxy(12, 21);
        printf("Data invalida!");
        goto finalizar;
    }

    aux = inicioMov;

    while (aux != NULL) {
        if (aux->numero > maiorNumero) {
            maiorNumero = aux->numero;
        }

        if (aux->codigoConta == codigo) {
            int dataAnterior = converterData(aux->data);

            if (dataAnterior > ultimaData) {
                ultimaData = dataAnterior;
            }
        }

        aux = aux->prox;
    }

    if (dataInformada < ultimaData) {
        gotoxy(12, 21);
        printf("Data anterior a ultima movimentacao!");
        goto finalizar;
    }

    nova = (MOVIMENTACAO *) malloc(sizeof(MOVIMENTACAO));

    if (nova == NULL) {
        gotoxy(12, 21);
        printf("Erro ao alocar memoria!");
        goto finalizar;
    }

    nova->numero = maiorNumero + 1;
    nova->codigoConta = codigo;
    nova->valor = valor;

    snprintf(nova->data, sizeof(nova->data), "%s", data);

    if (opcao == 1) {
        conta->saldo += valor;
        snprintf(nova->tipo, sizeof(nova->tipo), "Deposito");
    } else {
        conta->saldo -= valor;
        snprintf(nova->tipo, sizeof(nova->tipo), "Saque");
    }

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

    gotoxy(12, 23);
    printf("Movimentacao registrada com sucesso!");

    gotoxy(12, 24);
    printf("Novo saldo: R$ %.2f", conta->saldo);

finalizar:
    gotoxy(20, 30);
    printf("Pressione ENTER para continuar...");
    getchar();
    getchar();
}

void registrarMovimento(void) {
    int opcao;

    system("cls");

    printf("\n  1 - Registrar Entrada");
    printf("\n  2 - Registrar Saida");
    printf("\n\n  Escolha uma opcao: ");
    scanf("%d", &opcao);

    if (opcao == 1 || opcao == 2) {
        registrarMovimentoTipo(opcao);
    } else {
        printf("\n  Opcao invalida!");
        getchar();
        getchar();
    }
}

void consultarMovimento(void) {
    MOVIMENTACAO *aux = inicioMov;
    int codigo;
    int linha = 10;
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
            gotoxy(x, 17);
            printf("-");
        }

        for (int y = 3; y <= 17; y++) {
            gotoxy(10, y);
            printf("|");
            gotoxy(70, y);
            printf("|");
        }

        gotoxy(24, 5);
        printf("MOVIMENTACAO FINANCEIRA");

        gotoxy(15, 8);
        printf("1 - Registrar Entrada");

        gotoxy(15, 10);
        printf("2 - Registrar Saida");

        gotoxy(15, 12);
        printf("3 - Consultar Movimentacao");

        gotoxy(15, 14);
        printf("0 - Voltar");

        gotoxy(15, 16);
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                registrarMovimentoTipo(1);
                break;

            case 2:
                registrarMovimentoTipo(2);
                break;

            case 3:
                consultarMovimento();
                break;

            case 0:
                break;

            default:
                gotoxy(15, 19);
                printf("Opcao invalida!");
                gotoxy(15, 21);
                printf("Pressione ENTER para continuar...");
                getchar();
                getchar();
        }

    } while (opcao != 0);
}
