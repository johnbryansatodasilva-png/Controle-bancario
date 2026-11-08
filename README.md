# Sistema de Controle Bancário

## Descrição

Projeto acadêmico desenvolvido em linguagem C para realizar o cadastro e o gerenciamento de contas bancárias, movimentações financeiras e relatórios.

## Funcionalidades

- Cadastro de contas bancárias.
- Consulta das contas cadastradas.
- Alteração e exclusão de contas.
- Bloqueio da exclusão de contas que possuem movimentações registradas.
- Registro de depósitos e saques.
- Consulta do histórico de movimentações.
- Transferência entre contas.
- Relatórios de contas, movimentações, contas inativas e limites de crédito.
- Salvamento e carregamento dos dados em arquivos.

## Tecnologias

- Linguagem C.
- GCC (compilador).
- Visual Studio Code (ambiente de desenvolvimento).
- MSYS2 UCRT64 no ambiente Windows.

## Estrutura principal

Os arquivos `.c` contêm a implementação das funcionalidades e `funcoes.h` reúne as estruturas e os protótipos utilizados pelo programa.

## Requisitos para executar

- Windows.
- GCC instalado e disponível no terminal (por exemplo, pelo MSYS2 UCRT64).

## Como compilar

Abra o terminal na pasta do projeto. Crie a pasta de saída, caso ela ainda não exista:

```powershell
New-Item -ItemType Directory -Force output
```

Em seguida, compile com:

```powershell
gcc -Wall -Wextra -g3 main.c menu.c cadastrarConta.c inserirFinal.c inserirPosicao.c consultarConta.c movimentacao.c alterarConta.c gotoxy.c excluirConta.c relatorios.c transferencia.c arquivosSalvar.c -o output/Banco.exe
```

No VS Code, também é possível usar a tarefa **Compilar Sistema Bancario** com `Ctrl + Shift + B`, desde que o caminho do GCC configurado em `.vscode/tasks.json` corresponda à instalação do computador.

## Como executar

No PowerShell, a partir da pasta do projeto:

```powershell
.\output\Banco.exe
```

## Arquivos de dados

Durante a execução, o sistema utiliza `contas.dat` e `movimentacoes.dat` para armazenar os registros. Esses arquivos são criados/atualizados pelo próprio programa. Para iniciar uma base de dados limpa, feche o programa e remova esses arquivos; isso apagará os registros salvos localmente.

## Autor

Matheus Henrique Lopes da Silva
John Bryan Sato da Silva

## Projeto acadêmico

Sistema de Controle Bancário — Linguagem C.
