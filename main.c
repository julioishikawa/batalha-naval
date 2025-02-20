#include <stdio.h>
#include "board.h"
#include "navios.h"

int main(void) {
    int board[BOARD_SIZE][BOARD_SIZE]; // Matriz que representa o tabuleiro
    int i, j; // Variáveis de controle para os loops

    // Inicializa o tabuleiro com 0 (representando água)
    inicializaTabuleiro(board);

    // Declarando os vetores para representar os navios
    // Cada posição do vetor contém o valor 3, que indica a presença de uma parte do navio
    int navioHorizontal[SHIP_SIZE] = {3, 3, 3};
    int navioVertical[SHIP_SIZE]   = {3, 3, 3};
    int navioDiagonal1[SHIP_SIZE] = {3, 3, 3}; 
    int navioDiagonal2[SHIP_SIZE] = {3, 3, 3}; 

    // Coordenadas iniciais definidas diretamente no código para posicionar os navios
    // Navio horizontal: posição inicial definida por linha e coluna
    int inicioH_linha = 2, inicioH_coluna = 2;
    // Navio vertical: posição inicial definida por linha e coluna
    int inicioV_linha = 5, inicioV_coluna = 5;
    
    // Coordenadas iniciais definidas para posicionar os navios diagonais
    // Navio diagonal 1: posição inicial definida por linha e coluna
    int inicioD1_linha = 7, inicioD1_coluna = 0; // Navio diagonal 1 (descendente da esquerda para a direita)
    // Navio diagonal 2: posição inicial definida por linha e coluna
    int inicioD2_linha = 0, inicioD2_coluna = 9; // Navio diagonal 2 (descendente da direita para a esquerda)

    // Posiciona os navios no tabuleiro
    if (posicionaNavioHorizontal(board, inicioH_linha, inicioH_coluna, navioHorizontal) != 0)
        return 1;
    if (posicionaNavioVertical(board, inicioV_linha, inicioV_coluna, navioVertical) != 0)
        return 1;
    if (posicionaNavioDiagonal1(board, inicioD1_linha, inicioD1_coluna, navioDiagonal1) != 0)
        return 1;
    if (posicionaNavioDiagonal2(board, inicioD2_linha, inicioD2_coluna, navioDiagonal2) != 0)
        return 1;

    // Exibe o tabuleiro com identificadores (colunas de A a J e linhas de 1 a 10)
    imprimeTabuleiro(board);

    // Imprime as posições dos navios
    imprimePosicoesNavioHorizontal(inicioH_linha, inicioH_coluna);
    imprimePosicoesNavioVertical(inicioV_linha, inicioV_coluna);
    imprimePosicoesNavioDiagonal1(inicioD1_linha, inicioD1_coluna);
    imprimePosicoesNavioDiagonal2(inicioD2_linha, inicioD2_coluna);

    return 0;
}