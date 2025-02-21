#ifndef HABILIDADES_H
#define HABILIDADES_H

#include "board.h"

// Define as dimensões das matrizes de habilidade
#define SKILL_ROWS 3
#define SKILL_COLS 5

/*
  As funções abaixo geram matrizes de tamanho SKILL_ROWS x SKILL_COLS para cada habilidade,
  onde cada célula contém 0 ou 1. Posteriormente, essas matrizes serão usadas para aplicar o efeito
  da habilidade no tabuleiro, convertendo os 1's em 5's (sem sobrescrever os navios, que possuem valor 3).
*/

// Gera a matriz para a habilidade Cone
void geraHabilidadeCone(int skill[SKILL_ROWS][SKILL_COLS]);

// Gera a matriz para a habilidade Cruz
void geraHabilidadeCruz(int skill[SKILL_ROWS][SKILL_COLS]);

// Gera a matriz para a habilidade Octaedro
void geraHabilidadeOctaedro(int skill[SKILL_ROWS][SKILL_COLS]);

/*
  As funções a seguir aplicam a área de efeito de cada habilidade no tabuleiro (board).
  Cada célula da matriz de habilidade com valor 1 será convertida em 5 no board,
  caso a célula correspondente esteja com 0 (água).
*/

// Aplica a habilidade Cone no board
void aplicaHabilidadeCone(int board[BOARD_SIZE][BOARD_SIZE], int ability[SKILL_ROWS][SKILL_COLS], int origin_board_row, int origin_board_col);

// Aplica a habilidade Cruz no board
void aplicaHabilidadeCruz(int board[BOARD_SIZE][BOARD_SIZE], int ability[SKILL_ROWS][SKILL_COLS], int origin_board_row, int origin_board_col);

// Aplica a habilidade Octaedro no board
void aplicaHabilidadeOctaedro(int board[BOARD_SIZE][BOARD_SIZE], int ability[SKILL_ROWS][SKILL_COLS], int origin_board_row, int origin_board_col);

#endif // HABILIDADES_H