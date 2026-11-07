/*  AUTOR.....: Matheus Henrique Lopes da Silva
    DATA......: 31/10/2026

    GRUPO.....: Matheus Henrique RA: 439746-2026
                John Bryan RA: 437929-2026

    OBJETIVO..: 
*/


#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct conta {
    int codigo;
    char banco[50];
    int agencia;
    int numeroConta;
    char tipo[30];
    float saldo;
    float limite;
    int status;

    struct conta *ant;
    struct conta *prox;
} CONTA;

typedef struct movimentacao {
    int numero;
    int codigoConta;
    char data[11];
    char tipo[20];
    float valor;
    float saldoAtual;

    struct movimentacao *prox;
} MOVIMENTACAO;

extern CONTA *inicio;
extern MOVIMENTACAO *inicioMov;

void menuPrincipal(void);
void cadastrarConta(void);
void inserirFinal(CONTA *nova);
void consultarConta(void);
void menuMovimentacao(void);
void registrarMovimento(void);
void consultarMovimento(void);
void alterarConta(void);
void gotoxy(int x, int y);
void excluirConta(void);
void transferencia(void);
#endif
