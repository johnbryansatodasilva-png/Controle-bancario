
#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct ContaBancaria {
    int codigo_conta;
    char banco[50];
    char agencia[10];
    char numero_conta[20];
    char tipo_conta[20];
    double vl_saldo;
    double vl_limite;
    char status[10];

    struct ContaBancaria *ant;
    struct ContaBancaria *prox;

} ContaBancaria;

typedef struct Movimentacao {
    int sequencial;
    int codigo_conta;
    char dt_movimento[11];
    char tp_movimentacao[15];
    char ds_favorecido[50];
    double vl_movimento;
    double vl_saldo;

    struct Movimentacao *prox;

} Movimentacao;

#endif
