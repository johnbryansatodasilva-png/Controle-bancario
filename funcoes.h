/*  AUTOR.....: Matheus Henrique Lopes da Silva
    DATA......: 31/10/2026

    GRUPO.....: Matheus Henrique RA: 439746-2026
                John Bryan RA: 437929-2026

    OBJETIVO..: Declarar as estruturas, variaveis globais e prototipos das funcoes utilizadas no Sistema de Controle Bancario
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
void menuMovimentacao(void);

void cadastrarConta(void);
void inserirFinal(CONTA *nova);
void inserirPosicao(CONTA *nova, int posicao);
void consultarConta(void);
void alterarConta(void);
void excluirConta(void);
void listarContas(void);

void registrarMovimento(void);
void consultarMovimento(void);
int validarData(const char data[], int codigoConta);
int validarSaldo(float valor, float saldo, float limite);
void transferencia(void);

void relatorios(void);

void salvarArquivos(void);
void carregarArquivos(void);

void gotoxy(int x, int y);

#endif
