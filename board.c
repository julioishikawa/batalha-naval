#include <stdio.h>
#include "board.h"

/*
 * Função: inicializaTabuleiro
 * ----------------------------
 * Percorre cada célula do tabuleiro e atribui o valor 0,
 * indicando que a célula está cheia de água.
 */
void inicializaTabuleiro(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    // Loop para cada linha do tabuleiro
    for (i = 0; i < BOARD_SIZE; i++) {
        // Loop para cada coluna da linha atual
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;  // 0 representa água
        }
    }
}

/*
 * Função: imprimeTabuleiro
 * -------------------------
 * Exibe o tabuleiro no console com um cabeçalho para as colunas
 * (convertendo índices em letras) e para as linhas (numeradas de 1 a 10).
 * Percorre a matriz e imprime cada valor.
 */
void imprimeTabuleiro(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    
    // Imprime o cabeçalho das colunas
    printf("    ");
    for (j = 0; j < BOARD_SIZE; j++) {
        // Converte o índice da coluna em letra (0 -> A, 1 -> B, etc.)
        printf(" %c", 'A' + j);
    }
    printf("\n");
    
    // Imprime cada linha do tabuleiro
    for (i = 0; i < BOARD_SIZE; i++) {
        // Formata o número da linha para manter o alinhamento
        if (i + 1 < 10)
            printf(" %d  ", i + 1);
        else
            printf("%d  ", i + 1);
        // Imprime os valores de cada coluna na linha atual
        for (j = 0; j < BOARD_SIZE; j++) {
            printf(" %d", board[i][j]);
        }
        printf("\n");
    }
}