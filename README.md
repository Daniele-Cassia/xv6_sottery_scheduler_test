# Implementação do Lottery Scheduler no xv6-riscv

Este projeto implementa o algoritmo de escalonamento baseado em loteria (Lottery Scheduler) no sistema operacional xv6-riscv, conforme descrito no livro *Operating Systems: Three Easy Pieces* (OSTEP).

## Descrição

O Lottery Scheduler é um algoritmo de escalonamento probabilístico que atribui tickets a cada processo. A probabilidade de um processo ser escolhido para execução é proporcional ao número de tickets que possui.

## Funcionalidades Implementadas

1. **Alteração do Scheduler**: Modificação do escalonador para usar o algoritmo de loteria.
2. **Manutenção do Número Total de Tickets**: Variável global para manter o número total de tickets distribuídos entre processos executáveis.
3. **Exclusão de Processos Dormindo**: Processos em estado de sono (SLEEPING) não competem pelo tempo da CPU.
4. **Proteção com Spinlock**: Acesso concorrente à variável total de tickets protegido por um spinlock.
5. **Campo de Tickets para Cada Processo**: Cada processo possui um campo que armazena seu número de tickets.
6. **Contabilização de Tickets no Fork**: Processos filhos herdam os tickets dos processos pais.
7. **Herdar Tickets no Exec**: Processos mantêm seus tickets ao chamar `exec`.
8. **Recuperação de Tickets no Exit**: Recuperação de tickets quando um processo chama `exit`.
9. **Geração de Número Aleatório no Scheduler**: Modificação do scheduler para gerar um número aleatório e escolher o processo apropriado.
10. **Chamadas de Sistema (settickets e getpinfo)**: Implementação das chamadas de sistema para definir e obter informações sobre os tickets.

## Estrutura de Arquivos

- `proc.h`: Definições de estruturas e protótipos de funções.
- `proc.c`: Implementação das funções do escalonador e manipulação de processos.
- `sysproc.c`: Implementação das novas chamadas de sistema `settickets` e `getpinfo`.
- `pstat.h`: Definição da estrutura `pstat` para armazenar informações de processos.

