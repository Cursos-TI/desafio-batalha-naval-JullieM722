#include <stdio.h>

// Desafio Batalha Naval - MateCheck

char tab_jog [10][10];

void seu_mapa (){
    printf("-------------------- SEU MAPA --------------------\n\n");

    printf("  |  0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < 10; i++){
        printf("%d |  ",i);
        for (int j = 0; j < 10; j++){
            printf("%c | ", tab_jog[i][j]);
        }
        printf("\n--------------------------------------------\n");
    }
    printf("\n\n");
}
int main() {
    char tabuleiro[10][10];
    int menu;
    int escolha[2];
    int habilidade;
    /*
          |  0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
      ---------------------------------------------
        0 |  - | - | - | - | - | - | - | # | - | -
        1 |  - | - | X | - | - | # | # | # | # | #
        2 |  - | X | - | - | - | - | - | X | - | -
        3 |  - | - | - | - | # | - | - | - | X | -
        4 |  - | - | - | # | # | # | - | - | - | -
        5 |  - | - | - | - | # | - | - | X | - | -
        6 |  - | - | X | X | - | - | - | X | - | -
        7 |  - | # | # | # | - | - | - | - | - | -
        8 |  # | # | # | # | # | - | - | - | - | -
        9 |  - | - | - | - | - | - | - | - | - | -
    */

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            tabuleiro [i][j] = '-';
            tab_jog [i][j] = ' ';
        }
    }
   
   //poderes
    tabuleiro[0][7] = '#';
    tabuleiro[2][7] = '#';
    tabuleiro[3][4] = '#';
    tabuleiro[5][4] = '#';
    tabuleiro[6][2] = '#';
    for (int j = 5; j < 10; j++){
        tabuleiro [1][j] = '#';
        if (j == 7) continue;
    }
    for (int j = 3; j < 6; j++)
        tabuleiro [4][j] = '#';
    for (int i = 1; i < 4; i++)
        tabuleiro [7][i] = '#';
    for (int i = 0; i < 5; i++)
        tabuleiro [8][i] = '#';
        
    //Navio da vertical
    tabuleiro [7][5] = 'X';
    tabuleiro [7][6] = 'X';

    //Navio da horizontal
    tabuleiro [2][6] = 'X';
    tabuleiro [3][6] = 'X';

    //Navio da diagonal 1
    tabuleiro [1][2] = 'X';
    tabuleiro [2][1] = 'X';

    //Navio da diagonal 2
    tabuleiro [7][2] = 'X';
    tabuleiro [8][3] = 'X';

    do{
        printf("-------------------- MENU INTERATIVO --------------------\n\n\n");
        printf("Escolha uma opção:\n");
        printf("1 - Jogar\n");
        printf("2 - Ver respostas\n");
        printf("3 - Regras do jogo\n");
        printf("4 - Sair\n");
        scanf("%d", &menu);

        switch (menu){
            case 1:
                printf("\n\n-------------------- VAMOS JOGAR? --------------------\n\n");
                printf("Gostaria de usar algum poder?\n");
                printf("1 - Cone;\n");
                printf("2 - Octaero;\n");
                printf("3 - Cruz;\n");
                printf("4 - Não, prefiro usar as coordenadas.\n");
                scanf("%d", &habilidade);

                switch (habilidade){
                    case 1:
                        printf("\n********** PODER: CONE **********\n\n");
                        tab_jog[2][6] = 'X';
                        for (int i = 1; i < 4; i++)
                            tab_jog[i][7] = '#';
                        for (int i = 0; i < 5; i++)
                            tab_jog[i][8] = '#';
                        printf("\nVocê acertou!!\n\n");
                        seu_mapa();
                        break;

                    case 2:
                        printf("\n********** PODER: OCTAEDRO **********\n\n");
                        for (int i = 3; i < 6; i++)
                            tab_jog[4][i] = '#';
                        for (int i = 3; i < 6; i++){
                            tab_jog[i][5] = '#';
                            if (i == 4) continue;
                        }
                        printf("\nVocê errou!!\n\n");
                        seu_mapa();
                        break;
                    
                    case 3:
                        printf("\n********** PODER: CRUZ **********\n\n");
                        for (int i = 5; i < 10; i++)
                            tab_jog[i][1] = '#';
                        for (int i = 0; i < 3; i++){
                            tab_jog[7][i] = '#';
                        }
                        tab_jog[7][2] = 'X';
                        printf("\nVocê acertou!!\n\n");
                        seu_mapa();
                        break;

                    case 4:
                        printf("Selecione uma coordenada X, de 0 a 9 \n");
                        scanf("%d", &escolha[0]);

                        printf("\nSelecione uma coordenada Y, de 0 a 9 \n");
                        scanf("%d", &escolha[1]);

                        if (tabuleiro[escolha[0]][escolha[1]] == 'X'){
                            tab_jog[escolha[0]][escolha[1]] = 'X';
                            printf("\nVocê acertou!!\n\n");
                        } else{
                            tab_jog[escolha[0]][escolha[1]] = '-';
                            printf("\nVocê errou!!\n\n");
                        }
                        seu_mapa();
                        break;

                    default:
                        printf("***** VALOR INVÁLIDO *****");
                        break;
                }
            
            case 2:
                printf("-------------------- MAPA DO JOGO --------------------\n\n");
                printf("  |  0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9\n");
                printf("--------------------------------------------\n");
                for (int i = 0; i < 10; i++){
                    printf("%d |  ",i);
                    for (int j = 0; j < 10; j++){
                        printf("%c | ", tabuleiro[i][j]);
                    }
                    printf("\n--------------------------------------------\n");
                }
                break;
            
            case 3:
                printf("-------------------- REGRAS --------------------\n\n");
                printf("1 - No jogo batalha naval, você deve acertar onde estão posicionados os navios usando habilidades ou coordenadas X e Y;\n");
                printf("2 - O jogo possui um total de 3 poderes, sendo eles: cone, octaedro e cruz;");
                printf("3 - Será pedido uma coordenada por vez, ou seja, primeiro o valor de X e depois o valor de Y;\n");
                printf("4 - Após inserir as coordenas, será conferido se você acertou ou não algum navio;\n");
                printf("5 - cada barco possui 2 celulas, ou seja 2 coordenadas X e Y;\n");
                printf("6 - Tem um total de 4 navios, sendo 1 na horizontal, 1 na vertical e 2 na diagonal.\n");
                printf("Sinais: \n(-) Vazio \n(X) Navio \n( ) Vazio \n(#) Poder\n\n");
                break;

            case 4:
                printf("\n***** SAINDO... *****\n\n");
                break;
            
            default:
                printf("***** VALOR INVÁLIDO *****");
                break;
        }
    } while (menu != 4);
    return 0;
}