/*  AUTOR.....: Matheus Henrique Lopes da Silva
    DATA......: 07/11/2026

    GRUPO.....: Matheus Henrique RA: 439746-2026
                John Bryan RA: 437929-2026

    OBJETIVO..: Armazenar os dados das contas e movimentacoes em arquivos para preserva-los apos o encerramento do sistema
*/


#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void salvarArquivos(void) {
    FILE *arquivo;
    CONTA *conta;
    MOVIMENTACAO *mov;

    CONTA dadosConta;
    MOVIMENTACAO dadosMov;

    arquivo = fopen("contas.dat", "wb");

    if (arquivo == NULL) {
        printf("\nErro ao salvar as contas!");
        return;
    }

    conta = inicio;

    while (conta != NULL) {
        dadosConta = *conta;
        dadosConta.ant = NULL;
        dadosConta.prox = NULL;

        fwrite(&dadosConta, sizeof(CONTA), 1, arquivo);

        conta = conta->prox;
    }

    fclose(arquivo);

    arquivo = fopen("movimentacoes.dat", "wb");

    if (arquivo == NULL) {
        printf("\nErro ao salvar as movimentacoes!");
        return;
    }

    mov = inicioMov;

    while (mov != NULL) {
        dadosMov = *mov;
        dadosMov.prox = NULL;

        fwrite(&dadosMov, sizeof(MOVIMENTACAO), 1, arquivo);

        mov = mov->prox;
    }

    fclose(arquivo);
}


void carregarArquivos(void) {
    FILE *arquivo;

    CONTA dadosConta;
    CONTA *novaConta;
    CONTA *ultimaConta = NULL;

    MOVIMENTACAO dadosMov;
    MOVIMENTACAO *novaMov;
    MOVIMENTACAO *ultimaMov = NULL;

    arquivo = fopen("contas.dat", "rb");

    if (arquivo != NULL) {
        while (fread(&dadosConta, sizeof(CONTA), 1, arquivo) == 1) {

            novaConta = malloc(sizeof(CONTA));

            if (novaConta == NULL) {
                break;
            }

            *novaConta = dadosConta;
            novaConta->ant = ultimaConta;
            novaConta->prox = NULL;

            if (inicio == NULL) {
                inicio = novaConta;
            } else {
                ultimaConta->prox = novaConta;
            }

            ultimaConta = novaConta;
        }

        fclose(arquivo);
    }

    arquivo = fopen("movimentacoes.dat", "rb");

    if (arquivo != NULL) {
        while (fread(&dadosMov, sizeof(MOVIMENTACAO), 1, arquivo) == 1) {

            novaMov = malloc(sizeof(MOVIMENTACAO));

            if (novaMov == NULL) {
                break;
            }

            *novaMov = dadosMov;
            novaMov->prox = NULL;

            if (inicioMov == NULL) {
                inicioMov = novaMov;
            } else {
                ultimaMov->prox = novaMov;
            }

            ultimaMov = novaMov;
        }

        fclose(arquivo);
    }
}
