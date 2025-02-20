#include <stdio.h>
#include "board.h"

// Inicializa o tabuleiro com 0 (representando água)
void inicializaTabuleiro(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j; // Variáveis de controle para os loops
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

// Exibe o tabuleiro com identificadores (colunas de A a J e linhas de 1 a 10)
void imprimeTabuleiro(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    // Imprime o cabeçalho para as colunas (A a J)
    printf("    "); // Espaço extra para alinhar com os números/letras das linhas
    for (j = 0; j < BOARD_SIZE; j++) {
        // Imprime cada coluna como uma letra (A, B, C, ...), convertendo o índice em caractere
        printf(" %c", 'A' + j);
    }
    printf("\n");

    // Imprime cada linha do tabuleiro com seus respectivos números
    for (i = 0; i < BOARD_SIZE; i++) {
        // Verifica se o número da linha é menor que 10 para manter o alinhamento (1-9 vs. 10)
        if (i + 1 < 10)
            printf(" %d  ", i + 1);
        else
            printf("%d  ", i + 1);
        // Imprime os valores de cada coluna da linha
        for (j = 0; j < BOARD_SIZE; j++) {
            printf(" %d", board[i][j]);
        }
        printf("\n");
    }
}