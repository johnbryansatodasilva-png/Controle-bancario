#include <stdio.h>

int main() {
    int opcao;

    do {
        printf("\n=================================\n");
        printf("    SISTEMA DE CONTROLE BANCARIO\n");
        printf("=================================\n");
        printf("1 - Cadastrar conta\n");
        printf("2 - Consultar contas\n");
        printf("3 - Alterar conta\n");
        printf("4 - Excluir conta\n");
        printf("5 - Realizar movimentacao\n");
        printf("6 - Consultar saldo\n");
        printf("7 - Relatorios\n");
        printf("0 - Sair\n");
        printf("=================================\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Opcao de cadastro selecionada.\n");
                break;

            case 2:
                printf("Opcao de consulta selecionada.\n");
                break;

            case 3:
                printf("Opcao de alteracao selecionada.\n");
                break;

            case 4:
                printf("Opcao de exclusao selecionada.\n");
                break;

            case 5:
                printf("Opcao de movimentacao selecionada.\n");
                break;

            case 6:
                printf("Opcao de consulta de saldo selecionada.\n");
                break;

            case 7:
                printf("Opcao de relatorios selecionada.\n");
                break;

            case 0:
                printf("Encerrando o sistema...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}