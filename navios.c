#include <stdio.h>
#include "navios.h"

// Posiciona o navio horizontal copiando os valores do vetor para o tabuleiro
int posicionaNavioHorizontal(int board[BOARD_SIZE][BOARD_SIZE], int inicioH_linha, int inicioH_coluna, int navioHorizontal[]) {
    int i;
    // Valida se o navio horizontal cabe no tabuleiro
    if (inicioH_coluna + SHIP_SIZE > BOARD_SIZE) {
        printf("Erro: Navio horizontal extrapola os limites do tabuleiro.\n");
        return 1;
    }
    for (i = 0; i < SHIP_SIZE; i++) {
        // Verifica se a posição já está ocupada para evitar sobreposição
        if (board[inicioH_linha][inicioH_coluna + i] != 0) {
            printf("Erro: Sobreposicao detectada no navio horizontal.\n");
            return 1;
        }
        // Atribui o valor do vetor à posição correspondente no tabuleiro
        board[inicioH_linha][inicioH_coluna + i] = navioHorizontal[i];
    }
    return 0;
}

// Posiciona o navio vertical copiando os valores do vetor para o tabuleiro
int posicionaNavioVertical(int board[BOARD_SIZE][BOARD_SIZE], int inicioV_linha, int inicioV_coluna, int navioVertical[]) {
    int i;
    // Valida se o navio vertical cabe no tabuleiro
    if (inicioV_linha + SHIP_SIZE > BOARD_SIZE) {
        printf("Erro: Navio vertical extrapola os limites do tabuleiro.\n");
        return 1;
    }
    for (i = 0; i < SHIP_SIZE; i++) {
        // Verifica se a posição já está ocupada para evitar sobreposição
        if (board[inicioV_linha + i][inicioV_coluna] != 0) {
            printf("Erro: Sobreposicao detectada no navio vertical.\n");
            return 1;
        }
        // Atribui o valor do vetor à posição correspondente no tabuleiro
        board[inicioV_linha + i][inicioV_coluna] = navioVertical[i];
    }
    return 0;
}

// Posiciona o navio diagonal 1 copiando os valores do vetor para o tabuleiro
int posicionaNavioDiagonal1(int board[BOARD_SIZE][BOARD_SIZE], int inicioD1_linha, int inicioD1_coluna, int navioDiagonal1[]) {
    int i;
    // Valida se o navio diagonal 1 cabe no tabuleiro
    if (inicioD1_linha + SHIP_SIZE > BOARD_SIZE || inicioD1_coluna + SHIP_SIZE > BOARD_SIZE) {
        printf("Erro: Navio diagonal 1 extrapola os limites do tabuleiro.\n");
        return 1;
    }
    for (i = 0; i < SHIP_SIZE; i++) {
        // Verifica se a posição já está ocupada para evitar sobreposição
        if (board[inicioD1_linha + i][inicioD1_coluna + i] != 0) {
            printf("Erro: Sobreposicao detectada no navio diagonal 1.\n");
            return 1;
        }
        // Atribui o valor do vetor à posição correspondente no tabuleiro
        board[inicioD1_linha + i][inicioD1_coluna + i] = navioDiagonal1[i];
    }
    return 0;
}

// Posiciona o navio diagonal 2 copiando os valores do vetor para o tabuleiro
int posicionaNavioDiagonal2(int board[BOARD_SIZE][BOARD_SIZE], int inicioD2_linha, int inicioD2_coluna, int navioDiagonal2[]) {
    int i;
    // Valida se o navio diagonal 2 cabe no tabuleiro
    if (inicioD2_linha + SHIP_SIZE > BOARD_SIZE || inicioD2_coluna - SHIP_SIZE + 1 < 0) {
        printf("Erro: Navio diagonal 2 extrapola os limites do tabuleiro.\n");
        return 1;
    }
    for (i = 0; i < SHIP_SIZE; i++) {
        // Verifica se a posição já está ocupada para evitar sobreposição
        if (board[inicioD2_linha + i][inicioD2_coluna - i] != 0) {
            printf("Erro: Sobreposicao detectada no navio diagonal 2.\n");
            return 1;
        }
        // Atribui o valor do vetor à posição correspondente no tabuleiro
        board[inicioD2_linha + i][inicioD2_coluna - i] = navioDiagonal2[i];
    }
    return 0;
}

// Imprime um cabeçalho para identificar as posições do navio horizontal
void imprimePosicoesNavioHorizontal(int inicioH_linha, int inicioH_coluna) {
    int i;
    printf("\nPosicoes do navio horizontal:\n");
    // Loop que percorre cada segmento do navio horizontal (total de SHIP_SIZE segmentos)
    for (i = 0; i < SHIP_SIZE; i++) {
        /*
         * Para o navio horizontal:
         * - A linha é fixa, definida por 'inicioH_linha'. Como o índice do array começa em 0, somamos 1 para que o usuário veja a linha iniciando em 1.
         * - A coluna varia: começamos em 'inicioH_coluna' e, para cada segmento, incrementamos o valor de 'i'. Adicionamos esse resultado a letra 
         *   'A' (usando a soma com caracteres) para converter o índice da coluna em uma letra (por exemplo, 0 -> 'A', 1 -> 'B', etc.).
         */
        printf("Segmento %d: Linha %d, Coluna %c\n", i + 1, inicioH_linha + 1, 'A' + (inicioH_coluna + i));
    }
}

// Imprime um cabeçalho para identificar as posições do navio vertical
void imprimePosicoesNavioVertical(int inicioV_linha, int inicioV_coluna) {
    int i;
    printf("\nPosicoes do navio vertical:\n");
    // Loop que percorre cada segmento do navio vertical (total de SHIP_SIZE segmentos)
    for (i = 0; i < SHIP_SIZE; i++) {
        /*
         * Para o navio vertical:
         * - A coluna é fixa, definida por 'inicioV_coluna'. Convertida para uma letra da mesma forma que no navio horizontal, ou seja, 'A' + inicioV_coluna.
         * - A linha varia: começamos em 'inicioV_linha' e, para cada segmento, incrementamos 'i'. Adicionamos 1 para mostrar números de linha iniciando em 1.
         */
        printf("Segmento %d: Linha %d, Coluna %c\n", i + 1, inicioV_linha + i + 1, 'A' + inicioV_coluna);
    }
}

// Imprime um cabeçalho para identificar as posições do navio diagonal 1
void imprimePosicoesNavioDiagonal1(int inicioD1_linha, int inicioD1_coluna) {
    int i;
    printf("\nPosicoes do navio diagonal 1 (esq -> dir):\n");
    // Loop que percorre cada segmento do navio diagonal 1 (total de SHIP_SIZE segmentos)
    for (i = 0; i < SHIP_SIZE; i++) {
        /*
         * Para o navio diagonal 1:
         * - A posição varia tanto na linha quanto na coluna.
         * - Começamos em 'inicioD1_linha' e 'inicioD1_coluna' e, para cada segmento, incrementamos 'i'.
         * - Somamos 1 na linha para exibição ao usuário.
         */
        printf("Segmento %d: Linha %d, Coluna %c\n", i + 1, inicioD1_linha + i + 1, 'A' + (inicioD1_coluna + i));
    }
}

// Imprime um cabeçalho para identificar as posições do navio diagonal 2
void imprimePosicoesNavioDiagonal2(int inicioD2_linha, int inicioD2_coluna) {
    int i;
    printf("\nPosicoes do navio diagonal 2 (dir -> esq):\n");
    // Loop que percorre cada segmento do navio diagonal 2 (total de SHIP_SIZE segmentos)
    for (i = 0; i < SHIP_SIZE; i++) {
        /*
         * Para o navio diagonal 2:
         * - A posição varia tanto na linha quanto na coluna.
         * - Começamos em 'inicioD2_linha' e 'inicioD2_coluna' e, para cada segmento, incrementamos 'i'.
         * - Somamos 1 na linha para exibição ao usuário.
         */
        printf("Segmento %d: Linha %d, Coluna %c\n", i + 1, inicioD2_linha + i + 1, 'A' + (inicioD2_coluna - i));
    }
}