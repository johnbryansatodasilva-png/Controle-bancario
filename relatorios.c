
/*  AUTOR.....: Matheus Henrique Lopes da Silva
    DATA......: 07/11/2026

    GRUPO.....: Matheus Henrique RA: 439746-2026
                John Bryan RA: 437929-2026

    OBJETIVO..: Gerar relatorios com informacoes das contas cadastradas e das movimentacoes bancarias realizadas
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

void relatorios(void) {
    int opcao;
    int totalContas;
    int ativas;
    int inativas;
    int totalMovimentos;
    int depositos;
    int saques;
    float saldoTotal;
    float totalDepositos;
    float totalSaques;

    CONTA *conta;
    MOVIMENTACAO *mov;

    do {
        system("cls");

        for (int x = 10; x <= 75; x++) {
            gotoxy(x, 3);
            printf("-");
            gotoxy(x, 20);
            printf("-");
        }

        for (int y = 3; y <= 20; y++) {
            gotoxy(10, y);
            printf("|");
            gotoxy(75, y);
            printf("|");
        }

        gotoxy(30, 5);
        printf("RELATORIOS");

        gotoxy(15, 8);
        printf("1 - Relatorio de contas");

        gotoxy(15, 10);
        printf("2 - Relatorio de movimentacoes");

        gotoxy(15, 12);
        printf("0 - Voltar");

        gotoxy(15, 15);
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            totalContas = 0;
            ativas = 0;
            inativas = 0;
            saldoTotal = 0;

            conta = inicio;

            while (conta != NULL) {
                totalContas++;
                saldoTotal += conta->saldo;

                if (conta->status == 1) {
                    ativas++;
                } else {
                    inativas++;
                }

                conta = conta->prox;
            }

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

            gotoxy(27, 5);
            printf("RELATORIO DE CONTAS");

            gotoxy(15, 9);
            printf("Total de contas: %d", totalContas);

            gotoxy(15, 11);
            printf("Contas ativas: %d", ativas);

            gotoxy(15, 13);
            printf("Contas inativas: %d", inativas);

            gotoxy(15, 15);
            printf("Saldo total: R$ %.2f", saldoTotal);

            if (totalContas == 0) {
                gotoxy(15, 18);
                printf("Nenhuma conta cadastrada!");
            }

            gotoxy(20, 23);
            printf("Pressione ENTER para continuar...");
            getchar();
            getchar();
        }

        else if (opcao == 2) {
            totalMovimentos = 0;
            depositos = 0;
            saques = 0;
            totalDepositos = 0;
            totalSaques = 0;

            mov = inicioMov;

            while (mov != NULL) {
                totalMovimentos++;

                if (strcmp(mov->tipo, "Deposito") == 0) {
                    depositos++;
                    totalDepositos += mov->valor;
                }
                else if (strcmp(mov->tipo, "Saque") == 0) {
                    saques++;
                    totalSaques += mov->valor;
                }

                mov = mov->prox;
            }

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

            gotoxy(23, 5);
            printf("RELATORIO DE MOVIMENTACOES");

            gotoxy(15, 9);
            printf("Total de movimentacoes: %d", totalMovimentos);

            gotoxy(15, 11);
            printf("Quantidade de depositos: %d", depositos);

            gotoxy(15, 13);
            printf("Total depositado: R$ %.2f", totalDepositos);

            gotoxy(15, 15);
            printf("Quantidade de saques: %d", saques);

            gotoxy(15, 17);
            printf("Total sacado: R$ %.2f", totalSaques);

            if (totalMovimentos == 0) {
                gotoxy(15, 20);
                printf("Nenhuma movimentacao cadastrada!");
            }

            gotoxy(20, 23);
            printf("Pressione ENTER para continuar...");
            getchar();
            getchar();
        }

        else if (opcao != 0) {
            gotoxy(15, 18);
            printf("Opcao invalida!");
            gotoxy(15, 22);
            printf("Pressione ENTER para continuar...");
            getchar();
            getchar();
        }

    } while (opcao != 0);
}
