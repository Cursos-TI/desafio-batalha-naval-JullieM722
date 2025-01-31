#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    char tabuleiro[10][10];
    char tab_jog [10][10];
    /*
          |  0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
      ---------------------------------------------
        0 |  - | - | - | - | - | - | - | - | - | -
        1 |  - | - | - | - | - | - | - | - | - | -
        2 |  - | - | - | - | - | - | - | - | - | -
        3 |  - | - | - | - | - | - | - | - | - | -
        4 |  - | - | - | - | - | - | - | - | - | -
        5 |  - | - | - | - | - | - | - | X | - | -
        6 |  - | - | X | X | - | - | - | X | - | -
        7 |  - | - | - | - | - | - | - | - | - | -
        8 |  - | - | - | - | - | - | - | - | - | -
        9 |  - | - | - | - | - | - | - | - | - | -
    */

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            tabuleiro [i][j] = '-';
            tab_jog [i][j] = '-';
        }
    }
   
    //Barco da vertical
    tabuleiro [7][5] = 'X';
    tabuleiro [7][6] = 'X';

    //Barco da horizontal
    tabuleiro [2][6] = 'X';
    tabuleiro [3][6] = 'X';
   
    int escolha[2];

    printf("Selecione uma coordenada X, de 0 a 9 \n");
    scanf("%d", &escolha[0]);

    printf("Selecione uma coordenada Y, de 0 a 9 \n");
    scanf("%d", &escolha[1]);

    if (tabuleiro[escolha[0]][escolha[1]] == 'X'){
        tab_jog[escolha[0]][escolha[1]] = 'X';
        printf("Você acertou!!\n\n");
    } else{
        tab_jog[escolha[0]][escolha[1]] = '-';
        printf("Você errou!!\n\n");
    }
    
    printf("Os navios estão posicionados nas seguintes coordenadas:");
    printf("Horizontal: X(2) Y(6) e x(3) Y(6)");
    printf("Vertical: X(7) Y(5) e x(7) Y(6)");



















    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
