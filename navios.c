#include <stdio.h>
#include "navios.h"

/*
 * Função: posicionaNavioHorizontal
 * ---------------------------------
 * Posiciona um navio na horizontal, copiando os valores do vetor
 * navioHorizontal para o board a partir das coordenadas (inicioH_linha, inicioH_coluna).
 *
 * Verifica se o navio cabe no tabuleiro e se as células estão desocupadas.
 *
 * Retorna 0 se o posicionamento ocorrer com sucesso, ou 1 em caso de erro.
 */
int posicionaNavioHorizontal(int board[BOARD_SIZE][BOARD_SIZE], int inicioH_linha, int inicioH_coluna, int navioHorizontal[]) {
    int i;
    // Verifica se o navio extrapola os limites do tabuleiro
    if (inicioH_coluna + SHIP_SIZE > BOARD_SIZE) {
        printf("Erro: Navio horizontal extrapola os limites do tabuleiro.\n");
        return 1;
    }
    // Posiciona cada segmento do navio na horizontal
    for (i = 0; i < SHIP_SIZE; i++) {
        // Verifica se a célula já está ocupada (diferente de 0)
        if (board[inicioH_linha][inicioH_coluna + i] != 0) {
            printf("Erro: Sobreposicao detectada no navio horizontal.\n");
            return 1;
        }
        // Atribui o valor do vetor (geralmente 3) à posição correspondente
        board[inicioH_linha][inicioH_coluna + i] = navioHorizontal[i];
    }
    return 0;
}

/*
 * Função: posicionaNavioVertical
 * -------------------------------
 * Posiciona um navio na vertical, copiando os valores do vetor
 * navioVertical para o board a partir de (inicioV_linha, inicioV_coluna).
 *
 * Verifica se o navio cabe no tabuleiro e se as células estão desocupadas.
 *
 * Retorna 0 se o posicionamento ocorrer com sucesso, ou 1 em caso de erro.
 */
int posicionaNavioVertical(int board[BOARD_SIZE][BOARD_SIZE], int inicioV_linha, int inicioV_coluna, int navioVertical[]) {
    int i;
    // Verifica se o navio vertical extrapola os limites do tabuleiro
    if (inicioV_linha + SHIP_SIZE > BOARD_SIZE) {
        printf("Erro: Navio vertical extrapola os limites do tabuleiro.\n");
        return 1;
    }
    // Posiciona cada segmento do navio na vertical
    for (i = 0; i < SHIP_SIZE; i++) {
        if (board[inicioV_linha + i][inicioV_coluna] != 0) {
            printf("Erro: Sobreposicao detectada no navio vertical.\n");
            return 1;
        }
        board[inicioV_linha + i][inicioV_coluna] = navioVertical[i];
    }
    return 0;
}

/*
 * Função: posicionaNavioDiagonal1
 * --------------------------------
 * Posiciona um navio na diagonal (descendente da esquerda para a direita)
 * copiando os valores do vetor navioDiagonal1 para o board a partir de
 * (inicioD1_linha, inicioD1_coluna).
 *
 * Verifica se o navio cabe dentro dos limites e se não há sobreposição.
 *
 * Retorna 0 se o posicionamento ocorrer com sucesso ou 1 em caso de erro.
 */
int posicionaNavioDiagonal1(int board[BOARD_SIZE][BOARD_SIZE], int inicioD1_linha, int inicioD1_coluna, int navioDiagonal1[]) {
    int i;
    // Verifica se o navio cabe na diagonal
    if (inicioD1_linha + SHIP_SIZE > BOARD_SIZE || inicioD1_coluna + SHIP_SIZE > BOARD_SIZE) {
        printf("Erro: Navio diagonal 1 extrapola os limites do tabuleiro.\n");
        return 1;
    }
    for (i = 0; i < SHIP_SIZE; i++) {
        if (board[inicioD1_linha + i][inicioD1_coluna + i] != 0) {
            printf("Erro: Sobreposicao detectada no navio diagonal 1.\n");
            return 1;
        }
        board[inicioD1_linha + i][inicioD1_coluna + i] = navioDiagonal1[i];
    }
    return 0;
}

/*
 * Função: posicionaNavioDiagonal2
 * --------------------------------
 * Posiciona um navio na diagonal (descendente da direita para a esquerda)
 * copiando os valores do vetor navioDiagonal2 para o board a partir de
 * (inicioD2_linha, inicioD2_coluna).
 *
 * Verifica se o navio cabe dentro dos limites e se não há sobreposição.
 *
 * Retorna 0 se o posicionamento ocorrer com sucesso ou 1 em caso de erro.
 */
int posicionaNavioDiagonal2(int board[BOARD_SIZE][BOARD_SIZE], int inicioD2_linha, int inicioD2_coluna, int navioDiagonal2[]) {
    int i;
    // Verifica se o navio cabe na diagonal
    if (inicioD2_linha + SHIP_SIZE > BOARD_SIZE || inicioD2_coluna - SHIP_SIZE + 1 < 0) {
        printf("Erro: Navio diagonal 2 extrapola os limites do tabuleiro.\n");
        return 1;
    }
    for (i = 0; i < SHIP_SIZE; i++) {
        if (board[inicioD2_linha + i][inicioD2_coluna - i] != 0) {
            printf("Erro: Sobreposicao detectada no navio diagonal 2.\n");
            return 1;
        }
        board[inicioD2_linha + i][inicioD2_coluna - i] = navioDiagonal2[i];
    }
    return 0;
}

/*
 * Função: imprimePosicoesNavioHorizontal
 * ---------------------------------------
 * Imprime as posições de cada segmento de um navio horizontal.
 *
 * Para o navio horizontal, a linha é fixa (inicioH_linha) e a coluna varia
 * a partir de inicioH_coluna. Os índices são convertidos para uma numeração
 * amigável ao usuário (linha: +1, coluna: convertida para letra).
 */
void imprimePosicoesNavioHorizontal(int inicioH_linha, int inicioH_coluna) {
    int i;
    printf("\nPosicoes do navio horizontal:\n");
    for (i = 0; i < SHIP_SIZE; i++) {
        printf("Segmento %d: Linha %d, Coluna %c\n", 
               i + 1,               // Segmento 1, 2, 3...
               inicioH_linha + 1,   // Converte índice de linha para exibição (1-indexado)
               'A' + (inicioH_coluna + i)); // Converte índice de coluna para letra
    }
}

/*
 * Função: imprimePosicoesNavioVertical
 * -------------------------------------
 * Imprime as posições de cada segmento de um navio vertical.
 *
 * Neste caso, a coluna é fixa e a linha varia, incrementando a partir de inicioV_linha.
 */
void imprimePosicoesNavioVertical(int inicioV_linha, int inicioV_coluna) {
    int i;
    printf("\nPosicoes do navio vertical:\n");
    for (i = 0; i < SHIP_SIZE; i++) {
        printf("Segmento %d: Linha %d, Coluna %c\n", 
               i + 1, 
               inicioV_linha + i + 1,  // Incrementa a linha e ajusta para 1-indexado
               'A' + inicioV_coluna);  // Coluna fixa convertida para letra
    }
}

/*
 * Função: imprimePosicoesNavioDiagonal1
 * ---------------------------------------
 * Imprime as posições de cada segmento de um navio diagonal (esquerda para direita).
 * Tanto a linha quanto a coluna aumentam a partir das coordenadas iniciais.
 */
void imprimePosicoesNavioDiagonal1(int inicioD1_linha, int inicioD1_coluna) {
    int i;
    printf("\nPosicoes do navio diagonal 1 (esq -> dir):\n");
    for (i = 0; i < SHIP_SIZE; i++) {
        printf("Segmento %d: Linha %d, Coluna %c\n", 
               i + 1, 
               inicioD1_linha + i + 1, // Linha aumenta para exibição
               'A' + (inicioD1_coluna + i)); // Coluna aumenta e é convertida para letra
    }
}

/*
 * Função: imprimePosicoesNavioDiagonal2
 * ---------------------------------------
 * Imprime as posições de cada segmento de um navio diagonal (direita para esquerda).
 * A linha aumenta e a coluna diminui a partir das coordenadas iniciais.
 */
void imprimePosicoesNavioDiagonal2(int inicioD2_linha, int inicioD2_coluna) {
    int i;
    printf("\nPosicoes do navio diagonal 2 (dir -> esq):\n");
    for (i = 0; i < SHIP_SIZE; i++) {
        printf("Segmento %d: Linha %d, Coluna %c\n", 
               i + 1, 
               inicioD2_linha + i + 1, // Linha aumenta para exibição
               'A' + (inicioD2_coluna - i)); // Coluna diminui e é convertida para letra
    }
}