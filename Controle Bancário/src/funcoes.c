
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void incluirInicio() {

    // Reserva espaço na memória para uma nova conta
    ContaBancaria *nova = malloc(sizeof(ContaBancaria));

    // Verifica se a memória foi alocada corretamente
    if (nova == NULL) {
        printf("\nErro: nao foi possivel alocar memoria!\n");
        return;
    }

    printf("\n===== CADASTRO DE CONTA =====\n");


printf("Codigo da conta:\n");
scanf("%d", &nova->codigo_conta);

printf("Banco:\n");
scanf(" %49[^\n]", nova->banco);

printf("Agencia:\n");
scanf(" %9[^\n]", nova->agencia);

printf("Numero da conta:\n");
scanf(" %19[^\n]", nova->numero_conta);

printf("Tipo da conta:\n");
scanf(" %19[^\n]", nova->tipo_conta);

printf("Saldo inicial:\n");
scanf("%lf", &nova->vl_saldo);

printf("Limite da conta:\n");
scanf("%lf", &nova->vl_limite);

    // Define a conta como ativa
    snprintf(nova->status, sizeof(nova->status), "ATIVA");

    // Liga a nova conta ao inicio da lista
    nova->ant = NULL;
    nova->prox = inicioContas;

    // Atualiza o ponteiro anterior da antiga primeira conta
    if (inicioContas != NULL) {
        inicioContas->ant = nova;
    }

    // Atualiza o inicio da lista
    inicioContas = nova;

    printf("\nConta cadastrada com sucesso!\n");
}
