#include <stdio.h>

// Desafio Batalha Naval - MateCheck

char tab_jog [10][10];

void seu_mapa (){ //void para impremir o tabuleiro do usuario
    printf("-------------------- SEU MAPA --------------------\n\n");

    printf("  |  0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < 10; i++){
        printf("%d |  ",i);
        for (int j = 0; j < 10; j++){
            printf("%c | ", tab_jog[j][i]);
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

    //Prenchendo os tabuleiros
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            tabuleiro [i][j] = '-';//prenche o tabuleiro do jogo
            tab_jog [i][j] = ' ';//preenche o tabuleiro do usuario
        }
    }
   //Preenchendo o tabuleiro do jogo com os poderes
    tabuleiro[0][7] = '#';
    tabuleiro[2][7] = '#';
    tabuleiro[3][4] = '#';
    tabuleiro[5][4] = '#';
    tabuleiro[6][2] = '#';
    for (int j = 5; j < 10; j++){
        tabuleiro [1][j] = '#';
        if (j == 7) continue;//quando j = 7 vai pular o loop
    }
    for (int j = 3; j < 6; j++)
        tabuleiro [4][j] = '#';
    for (int i = 1; i < 4; i++)
        tabuleiro [7][i] = '#';
    for (int i = 0; i < 5; i++)
        tabuleiro [8][i] = '#';
        
    //Navio da vertical
    tabuleiro [5][7] = 'X';
    tabuleiro [6][7] = 'X';

    //Navio da horizontal
    tabuleiro [6][2] = 'X';
    tabuleiro [6][3] = 'X';

    //Navio da diagonal 1
    tabuleiro [2][1] = 'X';
    tabuleiro [1][2] = 'X';

    //Navio da diagonal 2
    tabuleiro [2][7] = 'X';
    tabuleiro [3][8] = 'X';

    do{ //menu interativo para o usuario escolher o que deseja fazer
        printf("-------------------- MENU INTERATIVO --------------------\n\n\n");
        printf("Escolha uma opção:\n");
        printf("1 - Jogar\n");
        printf("2 - Ver respostas\n");
        printf("3 - Regras do jogo\n");
        printf("4 - Sair\n");
        scanf("%d", &menu);

        switch (menu){ //switch para escolha do usuario
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
                        //Preenchendo o poder cone no tabuleiro do jogador
                        tab_jog[2][6] = 'X'; //houve acerto
                        for (int i = 1; i < 4; i++)
                            tab_jog[i][7] = '#';
                        for (int i = 0; i < 5; i++)
                            tab_jog[i][8] = '#';
                        printf("\nVocê acertou!!\n\n");
                        seu_mapa(); //chama o void so tabuleiro do jogador e o imprime no terminal
                        break;

                    case 2:
                        printf("\n********** PODER: OCTAEDRO **********\n\n");
                        //Preenchendo o poder octaedro no tabuleiro do jogador
                        tab_jog[3][4] = '#';
                        for (int i = 3; i < 6; i++)
                            tab_jog[4][i] = '#';
                        tab_jog[5][4] = '#';
                        printf("\nVocê errou!!\n\n");//nao houve acertos
                        seu_mapa(); //chama o void so tabuleiro do jogador e o imprime no terminal
                        break;
                    
                    case 3:
                        printf("\n********** PODER: CRUZ **********\n\n");
                        //Preenchendo o poder octaedro no tabuleiro do jogador
                        for (int i = 5; i < 10; i++)
                            tab_jog[i][1] = '#';
                        for (int i = 0; i < 3; i++){
                            tab_jog[7][i] = '#';
                        }
                        tab_jog[7][2] = 'X'; //acerto do usuario
                        printf("\nVocê Acertou!!\n\n");
                        seu_mapa(); //chama o void so tabuleiro do jogador e o imprime no terminal
                        break;

                    case 4:
                        printf("Selecione uma coordenada X, de 0 a 9 \n");
                        scanf("%d", &escolha[0]); //armazena a coordenada x

                        printf("\nSelecione uma coordenada Y, de 0 a 9 \n");
                        scanf("%d", &escolha[1]); //armazena a coordenada y

                        if (tabuleiro[escolha[1]][escolha[0]] == 'X'){ //confere se as corrdenadas dadas, se referem a um navio no tabuleiro do jogo
                            tab_jog[escolha[1]][escolha[0]] = 'X'; //se sim, imprime o X, representando acerto de um navio
                            printf("\nVocê acertou!!\n\n");
                        } else{
                            tab_jog[escolha[1]][escolha[0]] = '-';//Se nao, imprime - representando que acertou o "vazio"
                            printf("\nVocê errou!!\n\n");
                        }
                        seu_mapa();//chama o void so tabuleiro do jogador e o imprime no terminal
                        break;

                    default:
                        printf("***** VALOR INVÁLIDO *****");
                        break;
                }
                break;
            
            case 2: //imprime o tabuleiro do jogo no terminal
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
            
            case 3: //apresenta as regras do jogo
                printf("-------------------- REGRAS --------------------\n\n");
                printf("1 - No jogo batalha naval, você deve acertar onde estão posicionados os navios usando habilidades ou coordenadas X e Y;\n");
                printf("2 - O jogo possui um total de 3 poderes, sendo eles: cone, octaedro e cruz;");
                printf("3 - Será pedido uma coordenada por vez, ou seja, primeiro o valor de X e depois o valor de Y;\n");
                printf("4 - Após inserir as coordenas, será conferido se você acertou ou não algum navio;\n");
                printf("5 - cada barco possui 2 celulas, ou seja 2 coordenadas X e Y;\n");
                printf("6 - Tem um total de 4 navios, sendo 1 na horizontal, 1 na vertical e 2 na diagonal.\n");
                printf("Sinais: \n(-) Vazio \n(X) Navio \n( ) Vazio \n(#) Poder\n\n");
                break;

            case 4: //sai do jogo, fecha o código
                printf("\n***** SAINDO... *****\n\n");
                break;
            
            default:
                printf("***** VALOR INVÁLIDO *****");
                break;
        }
    } while (menu != 4);//Enquanto a variavel menu for diferente de 4 (sair/fechar) o loop continua
    return 0;// finaliza o codigo
}