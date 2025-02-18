#include <stdio.h>

#define BOARD_SIZE 10   // Tamanho do tabuleiro (10x10)
#define SHIP_SIZE 3     // Tamanho fixo de cada navio

int main(void) {
    int board[BOARD_SIZE][BOARD_SIZE]; // Matriz que representa o tabuleiro
    int i, j; // Variáveis de controle para os loops

    // Inicializa o tabuleiro com 0 (representando água)
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }

    // Declarando os vetores para representar os navios
    // Cada posição do vetor contém o valor 3, que indica a presença de uma parte do navio
    int navioHorizontal[SHIP_SIZE] = {3, 3, 3};
    int navioVertical[SHIP_SIZE]   = {3, 3, 3};

    // Coordenadas iniciais definidas diretamente no código para posicionar os navios
    // Navio horizontal: posição inicial definida por linha e coluna
    int inicioH_linha = 2, inicioH_coluna = 2;
    // Navio vertical: posição inicial definida por linha e coluna
    int inicioV_linha = 5, inicioV_coluna = 5;

    // Valida se o navio horizontal cabe no tabuleiro
    if (inicioH_coluna + SHIP_SIZE > BOARD_SIZE) {
        printf("Erro: Navio horizontal extrapola os limites do tabuleiro.\n");
        return 1;
    }
    // Valida se o navio vertical cabe no tabuleiro
    if (inicioV_linha + SHIP_SIZE > BOARD_SIZE) {
        printf("Erro: Navio vertical extrapola os limites do tabuleiro.\n");
        return 1;
    }

    // Posiciona o navio horizontal copiando os valores do vetor para o tabuleiro
    for (i = 0; i < SHIP_SIZE; i++) {
        // Verifica se a posição já está ocupada para evitar sobreposição
        if (board[inicioH_linha][inicioH_coluna + i] != 0) {
            printf("Erro: Sobreposicao detectada no navio horizontal.\n");
            return 1;
        }
        // Atribui o valor do vetor à posição correspondente no tabuleiro
        board[inicioH_linha][inicioH_coluna + i] = navioHorizontal[i];
    }

    // Posiciona o navio vertical copiando os valores do vetor para o tabuleiro
    for (i = 0; i < SHIP_SIZE; i++) {
        // Verifica se a posição já está ocupada para evitar sobreposição
        if (board[inicioV_linha + i][inicioV_coluna] != 0) {
            printf("Erro: Sobreposicao detectada no navio vertical.\n");
            return 1;
        }
        // Atribui o valor do vetor à posição correspondente no tabuleiro
        board[inicioV_linha + i][inicioV_coluna] = navioVertical[i];
    }

    // Exibe o tabuleiro com identificadores (colunas de A a J e linhas de 1 a 10)

    // Imprime o cabeçalho para as colunas (A a J)
    printf("    "); // Espaço extra para alinhar com os números das linhas
    for (j = 0; j < BOARD_SIZE; j++) {
        // Imprime cada coluna como uma letra (A, B, C, ...), convertendo o índice em caractere
        printf(" %c", 'A' + j);
    }
    printf("\n");

    // Imprime cada linha do tabuleiro com seus respectivos números
    for (i = 0; i < BOARD_SIZE; i++) {
        // Verifica se o número da linha é menor que 10 para manter o alinhamento (1-9 vs. 10)
        if (i + 1 < 10)
            printf(" %d  ", i + 1);
        else
            printf("%d  ", i + 1);
        // Imprime os valores de cada coluna da linha
        for (j = 0; j < BOARD_SIZE; j++) {
            printf(" %d", board[i][j]);
        }
        printf("\n");
    }

    // Imprime um cabeçalho para identificar as posições do navio horizontal
    printf("\nPosicoes do navio horizontal:\n");
    // Loop que percorre cada segmento do navio horizontal (total de SHIP_SIZE segmentos)
    for (i = 0; i < SHIP_SIZE; i++) {
        /*
         * Para o navio horizontal:
         * - A linha é fixa, definida por 'inicioH_linha'. Como o índice do array começa em 0, somamos 1 para que o usuário veja a linha iniciando em 1.
         * - A coluna varia: começamos em 'inicioH_coluna' e, para cada segmento, incrementamos o valor de 'i'. Adicionamos esse resultado a letra 
         *   'A' (usando a soma com caracteres) para converter o índice da coluna em uma letra (por exemplo, 0 -> 'A', 1 -> 'B', etc.).
         */
        printf("Segmento %d: Linha %d, Coluna %c\n", i + 1, 
               inicioH_linha + 1, 'A' + (inicioH_coluna + i));
    }

    // Imprime um cabeçalho para identificar as posições do navio vertical
    printf("\nPosicoes do navio vertical:\n");
    // Loop que percorre cada segmento do navio vertical (total de SHIP_SIZE segmentos)
    for (i = 0; i < SHIP_SIZE; i++) {
        /*
         * Para o navio vertical:
         * - A coluna é fixa, definida por 'inicioV_coluna'. Convertida para uma letra da mesma forma que no navio horizontal, ou seja, 'A' + inicioV_coluna.
         * - A linha varia: começamos em 'inicioV_linha' e, para cada segmento, incrementamos 'i'. Adicionamos 1 para mostrar números de linha iniciando em 1.
         */
        printf("Segmento %d: Linha %d, Coluna %c\n", i + 1, 
               inicioV_linha + i + 1, 'A' + inicioV_coluna);
    }

    return 0;
}
