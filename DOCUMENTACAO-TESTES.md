# Documentação de Testes – Sistema de Controle Bancário

## 1. Objetivo

Este documento apresenta os testes realizados no Sistema de Controle Bancário, com o objetivo de verificar o funcionamento das principais funcionalidades do programa.

## 2. Ambiente de Testes

- **Linguagem:** C
- **Compilador:** GCC
- **Ambiente de desenvolvimento:** Visual Studio Code
- **Sistema operacional:** Windows

## 3. Casos de Teste

| Nº | Funcionalidade | Teste realizado | Resultado esperado |
|---|---|---|---|
| 1 | Cadastro de conta | Cadastrar uma nova conta | Conta cadastrada corretamente |
| 2 | Cadastro de conta | Tentar cadastrar uma conta com código duplicado | Sistema deve impedir o cadastro |
| 3 | Consulta de contas | Consultar as contas cadastradas | Exibir os dados das contas |
| 4 | Alteração de conta | Alterar os dados de uma conta | Dados atualizados corretamente |
| 5 | Exclusão de conta | Tentar excluir uma conta com movimentações | Sistema deve impedir a exclusão |
| 6 | Exclusão de conta | Excluir uma conta sem movimentações | Conta removida corretamente |
| 7 | Depósito | Realizar um depósito | Saldo deve ser atualizado |
| 8 | Saque | Realizar um saque dentro do limite | Saldo deve ser atualizado |
| 9 | Saque | Tentar sacar acima do limite disponível | Sistema deve impedir a operação |
| 10 | Movimentações | Consultar as movimentações de uma conta | Exibir o histórico de movimentações |
| 11 | Validação de data | Informar uma data inválida | Sistema deve rejeitar a data |
| 12 | Validação de data | Informar movimentação anterior à última movimentação da conta | Sistema deve impedir a operação |
| 13 | Persistência | Fechar e abrir novamente o programa | Dados devem permanecer salvos |
| 14 | Relatórios | Consultar o relatório de todas as contas | Exibir as contas cadastradas |
| 15 | Relatórios | Consultar os relatórios de contas inativas e limites de crédito | Exibir os dados correspondentes |

## 4. Observações

Os testes devem ser executados com dados de demonstração. Os resultados de cada caso devem ser conferidos durante a execução do programa.

## 5. Conclusão

A documentação reúne os principais cenários de teste do Sistema de Controle Bancário, permitindo verificar suas funcionalidades e identificar possíveis problemas durante a utilização.