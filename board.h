#ifndef BOARD_H
#define BOARD_H

// Define o tamanho do tabuleiro (10 linhas x 10 colunas)
#define BOARD_SIZE 10

/*
 * Função: inicializaTabuleiro
 * ----------------------------
 * Preenche o tabuleiro com o valor 0, que representa água.
 *
 * Parâmetros:
 *   board - matriz que representa o tabuleiro
 */
void inicializaTabuleiro(int board[BOARD_SIZE][BOARD_SIZE]);

/*
 * Função: imprimeTabuleiro
 * -------------------------
 * Exibe o tabuleiro no console com cabeçalhos de linhas (1 a 10)
 * e colunas (A a J). Os valores podem ser 0 (água), 3 (navio) ou 5 (habilidade).
 *
 * Parâmetros:
 *   board - matriz que representa o tabuleiro
 */
void imprimeTabuleiro(int board[BOARD_SIZE][BOARD_SIZE]);

#endif // BOARD_H