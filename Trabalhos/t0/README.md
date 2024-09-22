# t0 - simulador de um computador 

O presente trabalho visa a implementação de um dispositivo que gera um número aleatório a cada vez que o programa é executado, fazendo com que o jogo de adivinhação seja mais divertido.

## Dispositivo random

Esse dispositivo foi implementado para gerar um número aleatório a cada vez que o programa executa. A implementação dele, assim como o restante dos dispositivos, foi feita em dois arquivos, um `.h` e um `.c`.

O `random.h` define o tipo opaco do dispositivo, além de declarar as funções de criação, destruição e leitura do dispositivo.

A especificação da estrutura do dispositivo, bem como das funções está no arquivo `random.c`.
A função `random_cria` aloca o espaço em memória para o dispositivo, certifica-se que a alocação ocorreu corretamente e retorna esse endereço para o ponteiro do dispositivo na `main.c`.

A função `random_destroi` é autoexplicativa. Já a função `random_leitura`, segue a interface da função de leitura de **E/S**. Para isso, ela recebe três argumentos: `void *disp`, que é o ponteiro genérico do dispositivo, `int id` que representa o identificador do dispositivo para o controlador de dispositivos e o `int *pvalor`, o ponteiro onde será colocado o valor da leitura. A função converte inicialmente o ponteiro `void` para um do tipo `random_t`, logo depois cria uma variável do tipo `err_t` e coloca o valor de `ERR_OK` nela. Após isso, entra em um `switch` que avalia o `id` para se certificar que o dispositivo recebido realmente é o de leitura. Caso esteja correto, realiza a criação de uma seed e geração do número aleatório entre 0 e 99, colocando esse valor no ponteiro `*pvalor`. Caso contrário, coloca o erro `ERR_DISP_INV` indicando que estamos querendo realizar uma operação inválida para o tipo de dispositivo em questão.

O programa `t0.asm` altera o original `ex5.asm` em algumas linhas, na 9 fazendo `RANDOM  DEFINE 18`, que define o código do dispositivo random implementado e nas linhas 13 e 14 ao fazer `LE RANDOM` e `armm segredo` que, respectivamente, pega o número aleatório gerado pelo dispositivo random e guarda-o no endereço `segredo`. O restante do programa é igual ao original, exceto na definição das strings, em que eu removi os acentos porque estavam sendo impressos bugados no terminal.