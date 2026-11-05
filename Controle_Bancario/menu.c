/*  AUTOR.....: Matheus Henrique Lopes da Silva
    DATA......: 31/10/2026

    GRUPO.....: Matheus Henrique RA: 439746-2026
                John Bryan RA: 437929-2026

    OBJETIVO..: 
*/


#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

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
        printf("  |  1 - Cadastro de contas                  |\n");
        printf("  |  2 - Consulta de contas                  |\n");
        printf("  |  3 - Alteracao de contas                 |\n");
        printf("  |  4 - Exclusao de contas                  |\n");
        printf("  |  5 - Movimentacoes                       |\n");
        printf("  |  6 - Relatorios                          |\n");
        printf("  |  0 - Sair                                |\n");
        printf("  |                                          |\n");
        printf("  +------------------------------------------+\n");
        printf("\n  Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarConta();
                break;

            case 2:
                consultarConta();
                break;

            case 3:
                alterarConta();
                break;

            case 4:
                printf("\n  Exclusao de contas selecionada.");
                break;

            case 5:
                menuMovimentacao();
                break;

            case 6:
                printf("\n  Relatorios selecionados.");
                break;

            case 0:
                printf("\n  Encerrando o sistema...");
                break;

            default:
                printf("\n  Opcao invalida!");
        }

        if (opcao != 0) {
            printf("\n\n  Pressione ENTER para continuar...");
            getchar();
            getchar();
        }

    } while (opcao != 0);
}
