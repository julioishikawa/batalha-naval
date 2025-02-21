#include <stdlib.h> // Necessário para a função abs()
#include "habilidades.h"

/*
  As funções abaixo geram as matrizes de habilidade no formato 3x5 (SKILL_ROWS x SKILL_COLS)
  onde cada célula pode ser 0 ou 1. Em seguida, as funções de aplicação percorrem essa
  matriz e, para cada 1, convertem para 5 no tabuleiro (board), desde que a célula correspondente
  esteja com 0 (água). Assim, não sobrescrevemos os navios (valor 3).

  Exemplos de formato esperado:
  
  Cone:
    0 0 1 0 0
    0 1 1 1 0
    1 1 1 1 1

  Cruz:
    0 0 1 0 0
    1 1 1 1 1
    0 0 1 0 0

  Octaedro (losango):
    0 0 1 0 0
    0 1 1 1 0
    0 0 1 0 0
*/

// Gera a matriz para a habilidade Cone
// O cone tem seu vértice no centro da primeira linha e se expande a cada linha.
void geraHabilidadeCone(int skill[SKILL_ROWS][SKILL_COLS]) {
    int center_col = SKILL_COLS / 2; // Determina a coluna central (para SKILL_COLS = 5, center = 2)
    // Percorre cada linha (row) e cada coluna (col) da matriz
    for (int row = 0; row < SKILL_ROWS; row++) {
        for (int col = 0; col < SKILL_COLS; col++) {
            // Se a coluna 'col' estiver dentro do intervalo que forma o cone para a linha 'row',
            // atribui 1; caso contrário, atribui 0.
            if (col >= center_col - row && col <= center_col + row)
                skill[row][col] = 1;
            else
                skill[row][col] = 0;
        }
    }
}

// Gera a matriz para a habilidade Cruz
// A cruz é definida de forma que apenas a coluna central e a linha central contenham 1.
void geraHabilidadeCruz(int skill[SKILL_ROWS][SKILL_COLS]) {
    int center_row = SKILL_ROWS / 2; // Linha central (para SKILL_ROWS = 3, center_row = 1)
    int center_col = SKILL_COLS / 2; // Coluna central (para SKILL_COLS = 5, center_col = 2)
    // Percorre todas as células da matriz
    for (int row = 0; row < SKILL_ROWS; row++) {
        for (int col = 0; col < SKILL_COLS; col++) {
            // Se a célula estiver na linha central ou na coluna central, marca 1; caso contrário, 0.
            if (row == center_row || col == center_col)
                skill[row][col] = 1;
            else
                skill[row][col] = 0;
        }
    }
}

// Gera a matriz para a habilidade Octaedro (losango)
// Utiliza a distância de Manhattan para determinar quais células devem receber 1.
void geraHabilidadeOctaedro(int skill[SKILL_ROWS][SKILL_COLS]) {
    int center_row = SKILL_ROWS / 2; // Linha central
    int center_col = SKILL_COLS / 2; // Coluna central
    // Percorre cada célula
    for (int row = 0; row < SKILL_ROWS; row++) {
        for (int col = 0; col < SKILL_COLS; col++) {
            // Se a soma das distâncias absolutas em relação ao centro for menor ou igual a 1,
            // a célula faz parte do losango e recebe 1.
            if (abs(row - center_row) + abs(col - center_col) <= 1)
                skill[row][col] = 1;
            else
                skill[row][col] = 0;
        }
    }
}

// Aplica a habilidade Cone no tabuleiro
// Para cada célula da matriz de habilidade que contém 1, se a célula correspondente no board (calculada a partir de origin_board_row e origin_board_col)
// estiver com 0 (água), ela recebe 5.
void aplicaHabilidadeCone(int board[BOARD_SIZE][BOARD_SIZE], int ability[SKILL_ROWS][SKILL_COLS], int origin_board_row, int origin_board_col) {
    int center_col = SKILL_COLS / 2; // Posição central da matriz de habilidade
    for (int row = 0; row < SKILL_ROWS; row++) {
        for (int col = 0; col < SKILL_COLS; col++) {
            if (ability[row][col] == 1) { // Se a célula faz parte da área de efeito
                // Calcula a posição no board: desloca com base na linha e ajusta a coluna para centralizar
                int target_row = origin_board_row + row;
                int target_col = origin_board_col + (col - center_col);
                // Verifica se a posição calculada está dentro dos limites do board
                if (target_row >= 0 && target_row < BOARD_SIZE && target_col >= 0 && target_col < BOARD_SIZE) {
                    // Só aplica se a célula estiver vazia (0), evitando sobrescrever navios (3)
                    if (board[target_row][target_col] == 0)
                        board[target_row][target_col] = 5;
                }
            }
        }
    }
}

// Aplica a habilidade Cruz no tabuleiro
// A matriz de habilidade é centralizada na posição (origin_board_row, origin_board_col)
void aplicaHabilidadeCruz(int board[BOARD_SIZE][BOARD_SIZE], int ability[SKILL_ROWS][SKILL_COLS], int origin_board_row, int origin_board_col) {
    int center_row = SKILL_ROWS / 2; // Linha central da matriz
    int center_col = SKILL_COLS / 2; // Coluna central da matriz
    for (int row = 0; row < SKILL_ROWS; row++) {
        for (int col = 0; col < SKILL_COLS; col++) {
            if (ability[row][col] == 1) {
                // Calcula a posição no board deslocando com base na centralização
                int target_row = origin_board_row + (row - center_row);
                int target_col = origin_board_col + (col - center_col);
                if (target_row >= 0 && target_row < BOARD_SIZE && target_col >= 0 && target_col < BOARD_SIZE) {
                    if (board[target_row][target_col] == 0)
                        board[target_row][target_col] = 5;
                }
            }
        }
    }
}

// Aplica a habilidade Octaedro no tabuleiro
// A lógica é similar à da habilidade Cruz, mas usa a matriz de Octaedro
void aplicaHabilidadeOctaedro(int board[BOARD_SIZE][BOARD_SIZE], int ability[SKILL_ROWS][SKILL_COLS], int origin_board_row, int origin_board_col) {
    int center_row = SKILL_ROWS / 2; // Linha central
    int center_col = SKILL_COLS / 2; // Coluna central
    for (int row = 0; row < SKILL_ROWS; row++) {
        for (int col = 0; col < SKILL_COLS; col++) {
            if (ability[row][col] == 1) {
                int target_row = origin_board_row + (row - center_row);
                int target_col = origin_board_col + (col - center_col);
                if (target_row >= 0 && target_row < BOARD_SIZE && target_col >= 0 && target_col < BOARD_SIZE) {
                    if (board[target_row][target_col] == 0)
                        board[target_row][target_col] = 5;
                }
            }
        }
    }
}