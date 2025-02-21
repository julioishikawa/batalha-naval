#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "navios.h"
#include "habilidades.h"

/*
  A função colocaNavios posiciona quatro navios de exemplo no tabuleiro 10x10,
  cada navio representado pelo valor 3. Esses navios são posicionados em locais fixos
  que não conflitam com as áreas usadas para a demonstração das habilidades.
*/
void colocaNavios(int board[BOARD_SIZE][BOARD_SIZE]) {
    int navioHorizontal[SHIP_SIZE] = {3, 3, 3};
    int navioVertical[SHIP_SIZE]   = {3, 3, 3};
    int navioDiagonal1[SHIP_SIZE]  = {3, 3, 3};
    int navioDiagonal2[SHIP_SIZE]  = {3, 3, 3};
    
    // Posiciona os navios em posições fixas:
    // - Navio horizontal no canto superior esquerdo
    // - Navio vertical no canto superior direito
    // - Navio diagonal (esq -> dir) na parte inferior esquerda
    // - Navio diagonal (dir -> esq) na parte inferior direita
    if (posicionaNavioHorizontal(board, 0, 0, navioHorizontal) != 0) exit(1);
    if (posicionaNavioVertical(board, 0, 9, navioVertical)   != 0) exit(1);
    if (posicionaNavioDiagonal1(board, 7, 0, navioDiagonal1) != 0) exit(1);
    if (posicionaNavioDiagonal2(board, 7, 9, navioDiagonal2) != 0) exit(1);
}

/*
  A função imprimeBoardComPreview exibe o tabuleiro (board) com a demonstração da habilidade
  aplicada e, ao lado, uma prévia da matriz da habilidade.
  - O board é impresso com cabeçalhos para colunas e linhas.
  - Nas primeiras SKILL_ROWS linhas, ao lado do board, é exibida a matriz de habilidade
    (convertendo cada 1 em 5 para visualização).
*/
void imprimeBoardComPreview(int board[BOARD_SIZE][BOARD_SIZE], int shape[SKILL_ROWS][SKILL_COLS], const char *habilidadeNome) {
    printf("\n=== Demonstracao da Habilidade: %s ===\n\n", habilidadeNome);
    
    // Cabeçalho das colunas do board
    printf("    ");
    for (int col = 0; col < BOARD_SIZE; col++) {
         printf(" %c", 'A' + col);
    }
    // Cabeçalho para a prévia da habilidade
    printf("       PREVIEW\n");
    
    // Imprime cada linha do board
    for (int row = 0; row < BOARD_SIZE; row++) {
        // Imprime o número da linha com formatação
        if (row + 1 < 10)
           printf(" %d  ", row + 1);
        else
           printf("%d  ", row + 1);
        // Imprime os valores do board
        for (int col = 0; col < BOARD_SIZE; col++) {
           printf(" %d", board[row][col]);
        }
        // Para as primeiras SKILL_ROWS linhas, imprime a prévia da habilidade (convertendo 1 em 5)
        if (row < SKILL_ROWS) {
            printf("      ");
            for (int c = 0; c < SKILL_COLS; c++) {
                int valorPreview = (shape[row][c] == 1) ? 5 : 0;
                printf(" %d", valorPreview);
            }
        }
        printf("\n");
    }
}

/*
  Função principal: apresenta um menu interativo para demonstrar as habilidades.
  - O usuário escolhe uma das três habilidades (Cone, Cruz, Octaedro) ou sai.
  - Para cada escolha, o tabuleiro é reinicializado, os navios são reposicionados,
    a matriz da habilidade é gerada e aplicada em uma área livre do board, e a demonstração
    é exibida junto com a prévia da habilidade.
  - O programa aguarda o usuário pressionar Enter para retornar ao menu.
*/
int main(void) {
    int opcao;
    int board[BOARD_SIZE][BOARD_SIZE];
    int shape[SKILL_ROWS][SKILL_COLS];  // Matriz de habilidade (3x5)

    while (1) {
        // Exibe o menu interativo
        printf("\n===== Menu de Demonstracao de Habilidades da Batalha Naval =====\n\n");
        printf("1. Demonstracao da Habilidade Cone\n");
        printf("2. Demonstracao da Habilidade Cruz\n");
        printf("3. Demonstracao da Habilidade Octaedro\n");
        printf("0. Sair\n");
        printf("\nDigite sua opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida.\n");
            while(getchar() != '\n'); // Limpa o buffer de entrada
            continue;
        }
        while(getchar() != '\n'); // Limpa o '\n' residual
        
        if (opcao == 0)
            break;
        
        // Reinicia o tabuleiro e posiciona os navios
        inicializaTabuleiro(board);
        colocaNavios(board);
        
        // Gera a matriz da habilidade e a aplica no board em uma área livre (para demonstração)
        if (opcao == 1) {
            geraHabilidadeCone(shape);
            // Aplica o Cone a partir da posição (4,5) no board
            aplicaHabilidadeCone(board, shape, 4, 5);
            imprimeBoardComPreview(board, shape, "Cone");
        } else if (opcao == 2) {
            geraHabilidadeCruz(shape);
            // Aplica a Cruz a partir da posição (6,6) no board
            aplicaHabilidadeCruz(board, shape, 6, 6);
            imprimeBoardComPreview(board, shape, "Cruz");
        } else if (opcao == 3) {
            geraHabilidadeOctaedro(shape);
            // Aplica o Octaedro a partir da posição (6,4) no board
            aplicaHabilidadeOctaedro(board, shape, 6, 4);
            imprimeBoardComPreview(board, shape, "Octaedro");
        } else {
            printf("Opcao invalida.\n");
            continue;
        }
        
        // Aguarda o usuário pressionar Enter para retornar ao menu
        printf("\nPressione Enter para retornar ao menu...");
        getchar();
    }
    
    return 0;
}