
#include <stdio.h>
#include "estruturas.h"
#include "funcoes.h"

ContaBancaria *inicioContas = NULL;

int main() {

    printf("=========================================================\n");
    printf("               SISTEMA DE CONTROLE BANCARIO              \n");
    printf("=========================================================\n");

    printf("\nSistema iniciado com sucesso!\n");

    // Chama a funcao de cadastro no inicio da lista
    incluirInicio();

    return 0;
}
