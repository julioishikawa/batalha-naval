#ifndef NAVIOS_H
#define NAVIOS_H

#include "board.h"

#define SHIP_SIZE 3     // Tamanho fixo de cada navio

// Funções para posicionamento dos navios
int posicionaNavioHorizontal(int board[BOARD_SIZE][BOARD_SIZE], int inicioH_linha, int inicioH_coluna, int navioHorizontal[]);
int posicionaNavioVertical(int board[BOARD_SIZE][BOARD_SIZE], int inicioV_linha, int inicioV_coluna, int navioVertical[]);
int posicionaNavioDiagonal1(int board[BOARD_SIZE][BOARD_SIZE], int inicioD1_linha, int inicioD1_coluna, int navioDiagonal1[]);
int posicionaNavioDiagonal2(int board[BOARD_SIZE][BOARD_SIZE], int inicioD2_linha, int inicioD2_coluna, int navioDiagonal2[]);

// Funções para imprimir as posições dos navios
void imprimePosicoesNavioHorizontal(int inicioH_linha, int inicioH_coluna);
void imprimePosicoesNavioVertical(int inicioV_linha, int inicioV_coluna);
void imprimePosicoesNavioDiagonal1(int inicioD1_linha, int inicioD1_coluna);
void imprimePosicoesNavioDiagonal2(int inicioD2_linha, int inicioD2_coluna);

#endif // NAVIOS_H