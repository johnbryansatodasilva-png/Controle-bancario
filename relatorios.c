
/*  AUTOR.....: Matheus Henrique Lopes da Silva
    DATA......: 07/11/2026

    GRUPO.....: Matheus Henrique RA: 439746-2026
                John Bryan RA: 437929-2026

    OBJETIVO..: Gerar relatorios com informacoes das contas cadastradas, movimentacoes, saldos e limites de credito
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

static void desenharTela(void) {
    system("cls");

    for (int x = 5; x <= 78; x++) {
        gotoxy(x, 3);
        printf("-");
        gotoxy(x, 27);
        printf("-");
    }

    for (int y = 3; y <= 27; y++) {
        gotoxy(5, y);
        printf("|");
        gotoxy(78, y);
        printf("|");
    }
}

static void pausarRelatorio(void) {
    gotoxy(18, 29);
    printf("Pressione ENTER para continuar...");
    getchar();
    getchar();
}

static void relatorioTodasContas(void) {
    CONTA *conta = inicio;
    int total = 0;
    int ativas = 0;
    int inativas = 0;
    float saldoTotal = 0;

    desenharTela();

    gotoxy(27, 5);
    printf("RELATORIO DE TODAS AS CONTAS");

    if (conta == NULL) {
        gotoxy(23, 14);
        printf("Nenhuma conta cadastrada!");
        pausarRelatorio();
        return;
    }

    while (conta != NULL) {
        total++;
        saldoTotal += conta->saldo;

        if (conta->status == 1) {
            ativas++;
        } else {
            inativas++;
        }

        conta = conta->prox;
    }

    conta = inicio;

    int linha = 8;
    int quantidade = 0;

    while (conta != NULL) {
        if (linha > 21) {
            gotoxy(12, 24);
            printf("Pressione ENTER para ver as proximas contas...");
            getchar();
            getchar();

            desenharTela();
            gotoxy(27, 5);
            printf("RELATORIO DE TODAS AS CONTAS");
            linha = 8;
        }

        gotoxy(10, linha++);
        printf("-----------------------------------------------");

        gotoxy(10, linha++);
        printf("Codigo: %d | Banco: %.20s", conta->codigo, conta->banco);

        gotoxy(10, linha++);
        printf("Agencia: %d | Numero: %d",
               conta->agencia, conta->numeroConta);

        gotoxy(10, linha++);
        printf("Tipo: %.15s | Saldo: R$ %.2f",
               conta->tipo, conta->saldo);

        gotoxy(10, linha++);
        printf("Limite: R$ %.2f | Status: %s",
               conta->limite,
               conta->status == 1 ? "Ativa" : "Inativa");

        linha++;
        quantidade++;

        conta = conta->prox;
    }

    gotoxy(10, 22);
    printf("Total de contas: %d | Ativas: %d | Inativas: %d",
           total, ativas, inativas);

    gotoxy(10, 24);
    printf("Saldo financeiro total: R$ %.2f", saldoTotal);

    pausarRelatorio();
}

static void relatorioMovimentacoesConta(void) {
    MOVIMENTACAO *mov = inicioMov;
    int codigo;
    int encontrou = 0;
    int linha = 10;

    desenharTela();

    gotoxy(25, 5);
    printf("MOVIMENTACOES POR CONTA");

    if (inicioMov == NULL) {
        gotoxy(20, 14);
        printf("Nenhuma movimentacao cadastrada!");
        pausarRelatorio();
        return;
    }

    gotoxy(10, 8);
    printf("Informe o codigo da conta: ");
    scanf("%d", &codigo);

    desenharTela();

    gotoxy(25, 5);
    printf("MOVIMENTACOES DA CONTA %d", codigo);

    gotoxy(9, 8);
    printf("NUMERO   DATA        TIPO       VALOR       SALDO");

    while (mov != NULL) {
        if (mov->codigoConta == codigo) {
            if (linha > 22) {
                gotoxy(10, 25);
                printf("Existem mais movimentacoes. Pressione ENTER...");
                getchar();
                getchar();

                desenharTela();
                gotoxy(25, 5);
                printf("MOVIMENTACOES DA CONTA %d", codigo);

                gotoxy(9, 8);
                printf("NUMERO   DATA        TIPO       VALOR       SALDO");

                linha = 10;
            }

            encontrou = 1;

            gotoxy(9, linha++);
            printf("%-8d %-11s %-10s R$ %-8.2f R$ %.2f",
                   mov->numero,
                   mov->data,
                   mov->tipo,
                   mov->valor,
                   mov->saldoAtual);
        }

        mov = mov->prox;
    }

    if (!encontrou) {
        gotoxy(18, 14);
        printf("Nenhuma movimentacao encontrada para esta conta!");
    }

    pausarRelatorio();
}

static void relatorioContasInativas(void) {
    CONTA *conta = inicio;
    int encontrou = 0;
    int linha = 9;

    desenharTela();

    gotoxy(28, 5);
    printf("RELATORIO DE CONTAS INATIVAS");

    while (conta != NULL) {
        if (conta->status != 1) {
            if (linha > 22) {
                gotoxy(10, 25);
                printf("Pressione ENTER para ver mais contas...");
                getchar();
                getchar();

                desenharTela();
                gotoxy(28, 5);
                printf("RELATORIO DE CONTAS INATIVAS");
                linha = 9;
            }

            encontrou = 1;

            gotoxy(10, linha++);
            printf("Codigo: %d | Banco: %.20s",
                   conta->codigo, conta->banco);

            gotoxy(10, linha++);
            printf("Agencia: %d | Conta: %d | Saldo: R$ %.2f",
                   conta->agencia,
                   conta->numeroConta,
                   conta->saldo);

            linha++;
        }

        conta = conta->prox;
    }

    if (!encontrou) {
        gotoxy(18, 14);
        printf("Nenhuma conta inativa encontrada!");
    }

    pausarRelatorio();
}

static void relatorioLimitesCredito(void) {
    CONTA *conta = inicio;
    int encontrou = 0;
    int linha = 9;

    desenharTela();

    gotoxy(26, 5);
    printf("RELATORIO DE LIMITES DE CREDITO");

    if (conta == NULL) {
        gotoxy(20, 14);
        printf("Nenhuma conta cadastrada!");
        pausarRelatorio();
        return;
    }

    while (conta != NULL) {
        if (linha > 22) {
            gotoxy(10, 25);
            printf("Pressione ENTER para ver mais contas...");
            getchar();
            getchar();

            desenharTela();
            gotoxy(26, 5);
            printf("RELATORIO DE LIMITES DE CREDITO");
            linha = 9;
        }

        encontrou = 1;

        gotoxy(10, linha++);
        printf("Conta: %d | Banco: %.20s",
               conta->codigo, conta->banco);

        gotoxy(10, linha++);
        printf("Saldo: R$ %.2f | Limite: R$ %.2f",
               conta->saldo, conta->limite);

        gotoxy(10, linha++);
        printf("Disponivel para utilizacao: R$ %.2f",
               conta->saldo + conta->limite);

        linha++;

        conta = conta->prox;
    }

    if (!encontrou) {
        gotoxy(18, 14);
        printf("Nenhuma conta encontrada!");
    }

    pausarRelatorio();
}

void relatorios(void) {
    int opcao;

    do {
        system("cls");

        for (int x = 10; x <= 75; x++) {
            gotoxy(x, 3);
            printf("-");
            gotoxy(x, 22);
            printf("-");
        }

        for (int y = 3; y <= 22; y++) {
            gotoxy(10, y);
            printf("|");
            gotoxy(75, y);
            printf("|");
        }

        gotoxy(30, 5);
        printf("RELATORIOS");

        gotoxy(15, 8);
        printf("1 - Relatorio de todas as contas");

        gotoxy(15, 10);
        printf("2 - Relatorio de movimentacoes");

        gotoxy(15, 12);
        printf("3 - Relatorio de contas inativas");

        gotoxy(15, 14);
        printf("4 - Relatorio de limites de credito");

        gotoxy(15, 17);
        printf("0 - Voltar");

        gotoxy(15, 19);
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                relatorioTodasContas();
                break;

            case 2:
                relatorioMovimentacoesConta();
                break;

            case 3:
                relatorioContasInativas();
                break;

            case 4:
                relatorioLimitesCredito();
                break;

            case 0:
                break;

            default:
                gotoxy(15, 20);
                printf("Opcao invalida!");
                getchar();
                getchar();
        }

    } while (opcao != 0);
}
