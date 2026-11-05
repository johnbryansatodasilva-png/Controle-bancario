/*  AUTOR.....: Matheus Henrique Lopes da Silva
    DATA......: 31/10/2026

    GRUPO.....: Matheus Henrique RA: 439746-2026
                John Bryan RA: 437929-2026

    OBJETIVO..: Inicializar o programa e chamar o menu principal do sistema
*/


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcoes.h"

CONTA *inicio = NULL;
MOVIMENTACAO *inicioMov = NULL;

int main() {
    setlocale(LC_ALL, "Portuguese");

    menuPrincipal();

    return 0;
}
