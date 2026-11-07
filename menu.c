/*  AUTOR.....: Matheus Henrique Lopes da Silva
    DATA......: 31/10/2026

    GRUPO.....: Matheus Henrique RA: 439746-2026
                John Bryan RA: 437929-2026

    OBJETIVO..: Exibir as opcoes principais do sistema e permitir a navegacao entre as funcionalidades
*/



#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void menuCadastroContas(void) {
    int opcao;

    do {
        system("cls");

        printf("\n");
        printf("  +------------------------------------------+\n");
        printf("  |                                          |\n");
        printf("  |           CADASTRO DE CONTAS             |\n");
        printf("  |                                          |\n");
        printf("  +------------------------------------------+\n");
        printf("  |                                          |\n");
        printf("  |  1 - Incluir Conta                       |\n");
        printf("  |  2 - Alterar Conta                       |\n");
        printf("  |  3 - Consultar Conta                     |\n");
        printf("  |  4 - Remover Conta                       |\n");
        printf("  |  5 - Relatorios                          |\n");
        printf("  |  0 - Voltar                              |\n");
        printf("  |                                          |\n");
        printf("  +------------------------------------------+\n");
        printf("\n  Escolha uma opcao: ");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarConta();
                break;

            case 2:
                alterarConta();
                break;

            case 3:
                consultarConta();
                break;

            case 4:
                excluirConta();
                break;
            case 5:
                relatorios();
                break;

            case 0:
                break;

            default:
                printf("\n  Opcao invalida!");
                getchar();
                getchar();
        }

    } while (opcao != 0);
}

void menuPrincipal(void) {
    int opcao;

    do {
        system("cls");

        printf("\n");
        printf("  +------------------------------------------+\n");
        printf("  |                                          |\n");
        printf("  |       SISTEMA DE CONTROLE BANCARIO       |\n");
        printf("  |                                          |\n");
        printf("  +------------------------------------------+\n");
        printf("  |                                          |\n");
        printf("  |  1 - Cadastro de Contas                  |\n");
        printf("  |  2 - Movimentacao Financeira             |\n");
        printf("  |  3 - Sair                                |\n");
        printf("  |                                          |\n");
        printf("  +------------------------------------------+\n");
        printf("\n  Escolha uma opcao: ");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                menuCadastroContas();
                break;

            case 2:
                menuMovimentacao();
                break;

            case 3:
                salvarArquivos();
                printf("\n  Encerrando o sistema...");
                break;

            default:
                printf("\n  Opcao invalida!");
                getchar();
                getchar();
        }

    } while (opcao != 3);
}
