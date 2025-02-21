#ifndef NAVIOS_H
#define NAVIOS_H

#include "board.h"

// Define o tamanho fixo de cada navio (3 células)
#define SHIP_SIZE 3

/*
 * Declaração das funções de posicionamento dos navios no tabuleiro.
 * Cada função tenta posicionar um navio no board usando o valor 3.
 *
 * Parâmetros:
 *   board - matriz do tabuleiro
 *   inicioX_linha/inicioX_coluna - coordenadas de início para posicionar o navio
 *   navioX - vetor contendo os valores (3) que serão colocados no board
 */
int posicionaNavioHorizontal(int board[BOARD_SIZE][BOARD_SIZE], int inicioH_linha, int inicioH_coluna, int navioHorizontal[]);
int posicionaNavioVertical(int board[BOARD_SIZE][BOARD_SIZE], int inicioV_linha, int inicioV_coluna, int navioVertical[]);
int posicionaNavioDiagonal1(int board[BOARD_SIZE][BOARD_SIZE], int inicioD1_linha, int inicioD1_coluna, int navioDiagonal1[]);
int posicionaNavioDiagonal2(int board[BOARD_SIZE][BOARD_SIZE], int inicioD2_linha, int inicioD2_coluna, int navioDiagonal2[]);

/*
 * Declaração das funções de impressão das posições dos navios.
 * Essas funções podem ser úteis para depuração ou para exibir as
 * posições de cada segmento do navio para o usuário.
 */
void imprimePosicoesNavioHorizontal(int inicioH_linha, int inicioH_coluna);
void imprimePosicoesNavioVertical(int inicioV_linha, int inicioV_coluna);
void imprimePosicoesNavioDiagonal1(int inicioD1_linha, int inicioD1_coluna);
void imprimePosicoesNavioDiagonal2(int inicioD2_linha, int inicioD2_coluna);

#endif // NAVIOS_H