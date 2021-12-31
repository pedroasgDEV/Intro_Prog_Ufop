/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Arquivos cabeçalho
#include "jogo.h"
#include "cor.h"
#include "layouts.h"

jogo gera_matriz(jogo game, int nivel){ //Essa função gera uma matriz para um jogo novo
    srand(time(NULL)); //Semete para gerar numeros aleatorios

    int position;
    int repet;
    int confirm = 0; //variavel que confirma se ta tudo certo
    int troca;
    int sizestring;
    char temp[27];

    for(int i = 0; i < game.m; i++){
        for(int j = 0; j < game.n; j++){
           game.matriz[i][j] = '-'; //Gera uma matriz com as dimensões anteriores de '-'
        }
    }

    for(int i = 0; i < game.wrds; i++){ //Define a posição e coordenadas de cada palavra

        sizestring = strlen(game.palavras[i]); //Tamanho da palavra
        repet = 0; //Zera as repetições

        while (confirm == 0){
            /*O laço ira se repetir se o comfirm for zero ao final,
            ou seja ter dado algum erro, e ira ser definido uma nova posição
            e coordenadas para a palvra*/

            position = 0;
            confirm = 1; //Se não for alterado, todas as condições estão corretas

            switch (nivel){ //Define a posição da palavra pelo nivel
                case 1: position = rand() % 2; break; //Se for 0 será na horizontal, se for 1 será na vertical
                case 2: position = rand() % 4; break; //Se for 2 será na diagonal de cima para baixo,se for 3 de baixo para cima
                case 3: position = rand() % 8; break; //Se 4 5 6 7 será 0 1 2 3 com palavras invertidas
            }

            if(position > 3){ //Se a palavra precisar ser invetida
                for(int j = 0; j < sizestring; j++){
                    temp[j] = game.palavras[i][sizestring - j - 1];
                }
                temp[sizestring + 1] = '\0'; 
            }

            else{ //Se a palavra não precisar ser invertida
                strcpy(temp, game.palavras[i]);
            }

            for(int j = 0; j < sizestring; j++){ //Deixa as letras maiusculas
                if((temp[j] <= 'z') && (temp[j] >= 'a')){temp[j] -= 32;}
            }

            switch(position){ //Define as corredenadas iniciais e finais
                case 0: case 4://Se a palavra ficar na horizontal
                    game.wrdsspot[i][0] = rand() % (game.m + 1); //Linha inicial da palavra
                    game.wrdsspot[i][1] = rand() % ((game.n - sizestring) + 1); //Coluna inicial da palavra
                    game.wrdsspot[i][2] = game.wrdsspot[i][0]; //Linha final da palavra
                    game.wrdsspot[i][3] = game.wrdsspot[i][1] + sizestring - 1; //Coluna final da palavra

                    for(int j = game.wrdsspot[i][1], k = 0; j <= game.wrdsspot[i][3]; j++, k++){ //Laço ira varrer a area que a palavra vai vicar em busca de algum impecilio
                        if((game.matriz[game.wrdsspot[i][0]][j] != '-') && //Se no locoal tiver uma letra
                        (game.matriz[game.wrdsspot[i][0]][j] != temp[k])){confirm = 0; break;} //Se a letra no local for diferente da letra correspontende na palavra o comfirm muda e o laço se repete
                    }

                    if(confirm == 1){ //Se tiver tudo certo no local que a palavra vai ficar
                        for(int j = game.wrdsspot[i][1], k = 0; j <= game.wrdsspot[i][3]; j++, k++){ //Laço ira alocar a palavra na matriz
                            game.matriz[game.wrdsspot[i][0]][j] = temp[k];
                        }
                    }

                    break;

                case 1: case 5: //Se a palavra ficar na vertical
                    game.wrdsspot[i][0] = rand() % ((game.m - sizestring) + 1); //Linha inicial da palavra
                    game.wrdsspot[i][1] = rand() % (game.n + 1); //Coluna inicial da palavra
                    game.wrdsspot[i][2] = game.wrdsspot[i][0] + sizestring - 1; //Linha final da palavra
                    game.wrdsspot[i][3] = game.wrdsspot[i][1]; //Coluna final da palavra

                    for(int j = game.wrdsspot[i][0], k = 0; j <= game.wrdsspot[i][2]; j++, k++){ //Laço ira varrer a area que a palavra vai vicar em busca de impecilio             
                        if((game.matriz[j][game.wrdsspot[i][1]] != '-') && //Se no locoal tiver uma letra
                        (game.matriz[j][game.wrdsspot[i][1]] != temp[k])){confirm = 0; break;} //Se a letra no local for diferente da letra correspontende na palavra o comfirm muda e o laço se repete
                    }

                    if(confirm == 1){ //Se tiver tudo certo no local que a palavra vai ficar
                        for(int j = game.wrdsspot[i][0], k = 0; j <= game.wrdsspot[i][2]; j++, k++){ //Laço ira alocar a palavra na matriz
                            game.matriz[j][game.wrdsspot[i][1]] = temp[k];
                        }
                    }

                    break;
                
                case 2: case 6://Se a palavra ficar na diagonal de cima para baixo
                    game.wrdsspot[i][0] = rand() % ((game.m - sizestring) + 1); //Linha inicial da palavra
                    game.wrdsspot[i][1] = rand() % ((game.n - sizestring) + 1); //Coluna inicial da palavra
                    game.wrdsspot[i][2] = game.wrdsspot[i][0] + sizestring - 1; //Linha final da palavra
                    game.wrdsspot[i][3] = game.wrdsspot[i][1] + sizestring - 1; //Coluna final da palavra

                    for(int j = game.wrdsspot[i][0], p =  game.wrdsspot[i][1], k = 0; j <= game.wrdsspot[i][2]; j++, p++, k++){ //Laço ira varrer a area que a palvra vai vicar em busca de impecilio
                        if((game.matriz[j][p] != '-') && //Se no locoal tiver uma letra
                        (game.matriz[j][p] != temp[k])){confirm = 0; break;} //Se a letra no local for diferente da letra correspontende na palavra o comfirm muda e o laço se repete
                    }

                    if(confirm == 1){ //Se tiver tudo certo no local que a palavra vai ficar
                        for(int j = game.wrdsspot[i][0], p =  game.wrdsspot[i][1], k = 0; j <= game.wrdsspot[i][2]; j++, p++, k++){ //Laço ira alocar a palavra na matriz
                            game.matriz[j][p] = temp[k];
                        }
                    }

                    break; 

                case 3: case 7://Se a palavra ficar na diagonal de baixo para cima
                    game.wrdsspot[i][2] = rand() % ((game.m - sizestring) + 1); //Linha final da palavra
                    game.wrdsspot[i][1] = rand() % ((game.n - sizestring) + 1); //Coluna inicial da palavra
                    game.wrdsspot[i][0] = game.wrdsspot[i][2] + sizestring - 1; //Linha inicial da palavra
                    game.wrdsspot[i][3] = game.wrdsspot[i][1] + sizestring - 1; //Coluna final da palavra

                    for(int j = game.wrdsspot[i][0], p =  game.wrdsspot[i][1], k = 0; p <= game.wrdsspot[i][3]; j--, p++, k++){ //Laço ira varrer a area que a palavra vai vicar em busca de impecilio
                        if((game.matriz[j][p] != '-') && //Se no locoal tiver uma letra
                        (game.matriz[j][p] != temp[k])){confirm = 0; break;} //Se a letra no local for diferente da letra correspontende na palavra ela o comfirm muda e o laço se repete
                    }

                    if(confirm == 1){ //Se tiver tudo certo no local que a palavra vai ficar
                        for(int j = game.wrdsspot[i][0], p =  game.wrdsspot[i][1], k = 0; p <= game.wrdsspot[i][3]; j--, p++, k++){ //Laço ira alocar a palavra na matriz
                            game.matriz[j][p] = temp[k];
                        }
                    }

                    break; 
            }

            if(position > 3){ //Inverte a coordenadas se a palavra tiver sido invertida
                troca = game.wrdsspot[i][2];
                game.wrdsspot[i][2] = game.wrdsspot[i][0];
                game.wrdsspot[i][0] = troca;
                troca = game.wrdsspot[i][3];
                game.wrdsspot[i][3] = game.wrdsspot[i][1];
                game.wrdsspot[i][1] = troca;
            }

            repet++; //Soma a quantidade de repetições do laço
            if(repet > 1000){arq_newgame(1);} //Para evitar looping infinitos
        }

        confirm = 0;
    }

    for(int i = 0; i < game.m; i++){ //Gera letras aleatorias para completar a matriz
        for(int j = 0; j < game.n; j++){
            if(game.matriz[i][j] == '-'){ game.matriz[i][j] = (char)( 65 + (rand() % 26));}
        }
    }

    return game;
}

jogo resolve(jogo game){ //Essa função resolve o caça-palvras e retornas as posições das palavras

    int confirm = 0; //variavel que confirma se ta tudo certo
    char temp[27];
    int sizestring;

    for(int i = 0; i < game.m; i++){
        for(int j = 0; j < game.n; j++){ //Varre toda a matriz atras das palavras
            for(int k = 0; k < game.wrds; k++){
                
                confirm = 0;
                if(game.wrdsspot[k][0] != -20){continue;} //Se a palavra ja tiver sido encontrada

                strcpy(temp, game.palavras[k]); //Copia a palavra para uma string temporaria

                sizestring = strlen(temp); //Tamanho da string 

                for(int j = 0; j < sizestring; j++){ //Deixa as letras maiusculas
                    if((temp[j] <= 'z') && (temp[j] >= 'a')){temp[j] -= 32;}
                }

                

                if(temp[0] == game.matriz[i][j]){ //Se a primeira letra da string for igual a letra da matriz
                    //Verifica horizontalmente
                    for(int p = j, a = 0; a < sizestring; p++, a++){ //Laço ira procurar a palavra
                        if((game.matriz[i][p] != temp[a]) || (p >= game.n)){confirm = 1; break;} //Não achou a palavra
                        confirm = 0;
                    }

                    if(confirm == 0){ //Se encontrar a palavra
                        game.wrdsspot[k][0] = i;
                        game.wrdsspot[k][1] = j;
                        game.wrdsspot[k][2] = i;
                        game.wrdsspot[k][3] = j + (sizestring - 1);
                        continue;
                    }

                    //Verifica horizontalmente palavra invertida
                    for(int p = j, a = 0; a < sizestring; p--, a++){ //Laço ira procurar a palavra
                        if((game.matriz[i][p] != temp[a]) || (p < 0)){confirm = 1; break;} //Não achou a palavra
                        confirm = 0;
                    }

                    if(confirm == 0){ //Se encontrar a palavra
                        game.wrdsspot[k][0] = i;
                        game.wrdsspot[k][1] = j;
                        game.wrdsspot[k][2] = i;
                        game.wrdsspot[k][3] = j - (sizestring - 1);
                        continue;
                    }

                    //Verifica verticalmente
                    for(int p = i, a = 0; a < sizestring; p++, a++){ //Laço ira procurar a palavra
                        if((game.matriz[p][j] != temp[a]) || (p >= game.m)){confirm = 1; break;} //Não achou a palavra
                        confirm = 0;
                    }

                    if(confirm == 0){ //Se encontrar a palavra
                        game.wrdsspot[k][0] = i;
                        game.wrdsspot[k][1] = j;
                        game.wrdsspot[k][2] = i + (sizestring - 1);
                        game.wrdsspot[k][3] = j;
                        continue;
                    }

                    //Verifica verticalmente palavra invertida
                    for(int p = i, a = 0; a < sizestring; p--, a++){ //Laço ira procurar a palavra
                        if((game.matriz[p][j] != temp[a]) || (p < 0)){confirm = 1; break;} //Não achou a palavra
                        confirm = 0;
                    }

                    if(confirm == 0){ //Se encontrar a palavra
                        game.wrdsspot[k][0] = i;
                        game.wrdsspot[k][1] = j;
                        game.wrdsspot[k][2] = i - (sizestring - 1);
                        game.wrdsspot[k][3] = j;
                        continue;
                    }

                    //Verifica diagonalmente de cima para baixo
                    for(int h = i, p = j, a = 0; a < sizestring; h++, p++, a++){ //Laço ira procurar a palavra
                        if((game.matriz[h][p] != temp[a]) || (p >= game.n) || (h >= game.m) ){confirm = 1; break;} //Não achou a palavra
                        confirm = 0;
                    }

                    if(confirm == 0){ //Se encontrar a palavra
                        game.wrdsspot[k][0] = i;
                        game.wrdsspot[k][1] = j;
                        game.wrdsspot[k][2] = i + (sizestring - 1);
                        game.wrdsspot[k][3] = j + (sizestring - 1);
                        continue;
                    }

                    //Verifica diagonalmente de cima para baixo palavra invertida
                    for(int h = i, p = j, a = 0; a < sizestring; h--, p--, a++){ //Laço ira procurar a palavra
                        if((game.matriz[h][p] != temp[a]) || (p < 0) || (h < 0) ){confirm = 1; break;} //Não achou a palavra
                        confirm = 0;
                    }

                    if(confirm == 0){ //Se encontrar a palavra
                        game.wrdsspot[k][0] = i;
                        game.wrdsspot[k][1] = j;
                        game.wrdsspot[k][2] = i - (sizestring - 1);
                        game.wrdsspot[k][3] = j - (sizestring - 1);
                        continue;
                    }

                    
                    //Verifica diagonalmente de baixo para cima
                    for(int h = i, p = j, a = 0; a < sizestring; h--, p++, a++){ //Laço ira procurar a palavra
                        if((game.matriz[h][p] != temp[a]) || (p >= game.n) || (h < 0) ){confirm = 1; break;} //Não achou a palavra
                        confirm = 0;
                    }

                    if(confirm == 0){ //Se encontrar a palavra
                        game.wrdsspot[k][0] = i;
                        game.wrdsspot[k][1] = j;
                        game.wrdsspot[k][2] = i - (sizestring - 1);
                        game.wrdsspot[k][3] = j + (sizestring - 1);
                        continue;
                    }

                    //Verifica diagonalmente de baixo para cima palavra invertida
                    for(int h = i, p = j, a = 0; a < sizestring; h++, p--, a++){ //Laço ira procurar a palavra
                        if((game.matriz[h][p] != temp[a]) || (p < 0) || (h >= game.m)){confirm = 1; break;} //Não achou a palavra
                        confirm = 0;
                    }

                    if(confirm == 0){ //Se encontrar a palavra
                        game.wrdsspot[k][0] = i;
                        game.wrdsspot[k][1] = j;
                        game.wrdsspot[k][2] = i + (sizestring - 1);
                        game.wrdsspot[k][3] = j - (sizestring - 1);
                        continue;
                    }
                }
            }
        }
    }

    return game; //Retorna a struct com as coordenadas
}

void salva_jogo(char arquivo[], jogo game){ //Salvar o jogo
    FILE *txt = fopen(arquivo, "w"); //Abre o arquivo

    fprintf(txt, "%d %d\n", game.m, game.n); //Coloca as dimensões da matriz 

    for(int i = 0; i < game.m; i++){ //Colocando a matriz no arquivo
        for(int j = 0; j < game.n; j++){
            fprintf(txt, "%c ", game.matriz[i][j]);
        }
        fprintf(txt, "\n");
    }
    
    fprintf(txt, "%d\n", game.wrds); //Coloca a quantidade de palavras

    for(int i = 0; i < game.wrds; i++){ //Coloca as palavras e suas coordenadas
        fprintf(txt, "%s %c%c %c%c\n", game.palavras[i], game.wrdsspot_ok[i][0] + 65,
        game.wrdsspot_ok[i][1] + 65, game.wrdsspot_ok[i][2] + 65, game.wrdsspot_ok[i][3] + 65);
    }

    fclose(txt);
}

void play_jogo(jogo game){ //Função que vai rodar o jogo
    //Variaveis da funação
    char escolha[20], localiza[4], arquivo[80] = "save.txt"; 
    int confirm; //variavel que confirma se ta tudo certo
    int tmn_str; 

    //Matriz de suporte para fazer as marcações das palavras
    int matriz[26][26];
    for(int i = 0; i < game.m; i++){
        for(int j = 0; j < game.n; j++){
            matriz[i][j] = 0;
        }
    }

    while (1){
        system(limpa); //Limpa a tela

        for(int i = 0; i < game.wrds; i++){ //Preenche a matrix suporte para marcações
            if(game.wrdsspot_ok[i][0] != -20){ //Se a palvra tiver sido encontrada

                if((game.wrdsspot_ok[i][1] > game.wrdsspot_ok[i][3]) ||
                   ((game.wrdsspot_ok[i][1] == game.wrdsspot_ok[i][3]) &&
                    (game.wrdsspot_ok[i][0] > game.wrdsspot_ok[i][2]))){ //inverte as cooredenadas das palvras invertidas para facilitar a marcação
                    localiza[0] = game.wrdsspot_ok[i][2];
                    localiza[1] = game.wrdsspot_ok[i][3];
                    localiza[2] = game.wrdsspot_ok[i][0];
                    localiza[3] = game.wrdsspot_ok[i][1];
                }

                else{ //Caso não estiver invertida vai continuar da msm forma
                    localiza[0] = game.wrdsspot_ok[i][0];
                    localiza[1] = game.wrdsspot_ok[i][1];
                    localiza[2] = game.wrdsspot_ok[i][2];
                    localiza[3] = game.wrdsspot_ok[i][3];
                }

                if(localiza[0] == localiza[2]){ //Caso a palvra for na horizontal
                    for(int j = localiza[1], k = 0; j <= localiza[3]; j++, k++){ //Laço ira marcar a palvra na matriz
                        matriz[(int) localiza[0]][j] = 1;
                    }
                }

                else if(localiza[1] == localiza[3]){ //Caso a palvra for na vertical
                    for(int j = localiza[0], k = 0; j <= localiza[2]; j++, k++){ //Laço ira marcar a palvra na matriz
                        matriz[j][(int) localiza[1]] = 1;
                    }
                }

                else if(localiza[0] < localiza[2]){ //Caso a palvra for na diagonal de cima para baixo
                    for(int j = localiza[0], p =  localiza[1], k = 0; j <= localiza[2]; j++, p++, k++){ //Laço ira marcar a palvra na matriz
                        matriz[j][p] = 1;
                    }
                }

                else{ //Caso a palvra for na diagonal de baixo para cima
                    for(int j = localiza[0], p =  localiza[1], k = 0; p <= localiza[3]; j--, p++, k++){ //Laço ira marcar a palvra na matriz
                        matriz[j][p] = 1;
                    }
                }

            }
        }

        //Parte de cima do caça-palavras
        printf("   ");
        for(int i = 65; i < game.n + 65; i++){
            printf(ANSI_BOLD  ANSI_COLOR_YELLOW "%4c" ANSI_RESET, (char) i);
        }
        printf("\n");

        //Parte de cima da estrutura do caça_palavras
        printf("    " TAB_TL TAB_HOR TAB_HOR TAB_HOR);
        for(int i = 0; i < game.n - 1; i++){
            printf(TAB_TJ TAB_HOR TAB_HOR  TAB_HOR );
        }
        printf(TAB_TR "\n");

        for(int i = 0; i < game.m; i++){
            //Parte lateral esquerda do caça-palavras
            printf(ANSI_BOLD  ANSI_COLOR_YELLOW "%3c " ANSI_RESET, (char) (i + 65)); 

            //Palavras do caça-palavras
            for(int j = 0; j < game.n; j++){
                printf(TAB_VER);

                if(matriz[i][j] == 1){ //Se esse caracter precisar ser marcado, ou seja pertence a uma palavra encontrada
                    printf(ANSI_BG_COLOR_YELLOW ANSI_COLOR_RED ANSI_BOLD "%2c " ANSI_RESET, game.matriz[i][j]);
                }

                else{printf("%2c ", game.matriz[i][j]);} //Caso o caracter não precise ser marcado
            }
            printf(TAB_VER);        
            
            //Parte lateral esquerda do caça-palavras
            printf(ANSI_BOLD  ANSI_COLOR_YELLOW " %c" ANSI_RESET, (char) (i + 65)); 
            
            //Meios do caça-palavras
            if(i < game.m - 1){
                printf("\n    " TAB_ML TAB_HOR TAB_HOR TAB_HOR);
                for(int j = 0; j < game.n - 1; j++){
                    printf(TAB_MJ TAB_HOR TAB_HOR TAB_HOR);
                }        
                printf(TAB_MR);
            }

            printf("\n");
        }

        //Parte de baixo da estrutura do caça_palavras
        printf("    " TAB_BL TAB_HOR TAB_HOR TAB_HOR);
        for(int i = 0; i < game.n - 1; i++){
            printf(TAB_BJ TAB_HOR TAB_HOR  TAB_HOR );
        }
        printf(TAB_BR "\n");   
        
        printf("   ");
        for(int i = 65; i < game.n + 65; i++){
            printf(ANSI_BOLD  ANSI_COLOR_YELLOW "%4c" ANSI_RESET, (char) i);
        }
        printf("\n\n");

        //Palavras que devem ser encontradas
        for(int i = 0; i < game.wrds; i++){
            if(game.wrdsspot_ok[i][0] != -20){ //Se a palvra tiver sido encontrada
                printf(ANSI_COLOR_GREEN "     %s %c%c %c%c\n" ANSI_RESET, game.palavras[i],
                    game.wrdsspot_ok[i][0] + 65, game.wrdsspot_ok[i][1] + 65, game.wrdsspot_ok[i][2] + 65,
                    game.wrdsspot_ok[i][3] + 65);
            }
            else{ //Caso não
                printf(ANSI_COLOR_RED ANSI_BOLD "     %s %c%c %c%c\n" ANSI_RESET, game.palavras[i],
                    game.wrdsspot_ok[i][0] + 65, game.wrdsspot_ok[i][1] + 65, game.wrdsspot_ok[i][2] + 65,
                    game.wrdsspot_ok[i][3] + 65);
            }
        }  
        printf("\n");

        if(game.acertos == game.wrds){read("files/parabens.txt"); main_layout(); break;} //Caso o jogador tenha achado todas as palavras
        else if(game.acertos == -1){read("files/resolver.txt"); main_layout(); break;} //Caso o jogador tenhar escolhido a opção resolver

        //Avisos
        printf("Digite \"sair\" para sair do jogo ou \"inicio\" para voltar a tela inicial\n");
        printf("Qualquer duvida vá à \"Instruções do jogo\" na tela inicial\n\n");

        while (1){
            
            //Entrada do usuario
            printf("Escolha entre \"marcar\" \"salvar\" \"resolver\": ");
            fgets(escolha, 100, stdin);          
            while(escolha[0] == '\n'){fgets(escolha, 100, stdin);} //Se caso pegar um quebra de linha antes

            for(int i = 0; i < strlen(escolha); i++){ //Delimita as palavras
                if((escolha[i] == ' ') || (escolha[i] == '\n')){escolha[i] = '\0'; break;}
            }
            
            tmn_str = strlen(escolha); //tamanho da palvra de entrada

            //Opções de escolha
            if(strcmp(escolha, "sair") == 0){printf("\nAté logo ;)\n\n"); exit(0);} //Caso o jogador queira sair
            else if(strcmp(escolha, "inicio") == 0){main_layout(); break;} //Caso o jogador queira voltar a tela inicial
            
            else if(strcmp(escolha, "salvar") == 0){ //Caso o jogador queira salvar o jogo
    
                confirm = 1;

                for(int i = tmn_str + 1, j = 0; 1; i++, j++){ //Laço que coloca o nome do arquivo em uma outra string
                    
                    if((j > 0) &&((escolha[i] == ' ') || (escolha[i] == '\n'))){ //se tiver chegado ao final da palavra
                        arquivo[j] = '\0'; 
                        break;
                    } 
                    if(escolha[i] < 33){confirm = 0; break;} //Se o nome do arquivo tiver um caracter invalido
                    arquivo[j] = escolha[i];
                } 
                
                //Se o nome do arquivo for invalido
                if(confirm == 0){printf("ERRO Nome de arquivo invalido\n"); continue;}

                salva_jogo(arquivo, game);
                printf("\nJogo salvo com sucesso ;)\n\n"); continue;
            } 
            
            else if(strcmp(escolha, "resolver") == 0){ //Caso o jogador queira mostrar as respostas
                for(int i = 0; i < game.wrds; i++){
                    game.wrdsspot_ok[i][0] = game.wrdsspot[i][0];
                    game.wrdsspot_ok[i][1] = game.wrdsspot[i][1];
                    game.wrdsspot_ok[i][2] = game.wrdsspot[i][2];
                    game.wrdsspot_ok[i][3] = game.wrdsspot[i][3];
                } game.acertos= -1; break;
            } 

            else if(strcmp(escolha, "marcar") == 0){ //Caso o jogador queira marcar uma palavra//

                //Retira as coordenadas da string de entrada
                localiza[0] = escolha[tmn_str + 1];
                localiza[1] = escolha[tmn_str + 2];
                localiza[2] = escolha[tmn_str + 4];
                localiza[3] = escolha[tmn_str + 5];


                confirm = 1; //Se não mudar para 0 ta tudo certo

                for(int j = 0; j < 4; j++){  //Verifica a estrutura de entrada das coordenadas 

                     if((localiza[j] <= 'z') && (localiza[j] >= 'a')){localiza[j] -= 32;}//Deixa as letras maiusculas

                    if((localiza[j] > 'Z') || (localiza[j] < 'A')){ //Se houver um caracter que não é letra nas coordenadas
                        printf("ERRO Há um caracter que não é letra nas coordenadas ou a estrutura da entrada das coordenadas é invalida\n");
                        confirm = 0;
                        break;
                    }
                    
                    localiza[j] -= 65;
                }

                if(confirm == 1){ //Se tiver tudo certo
                    for(int i = 0; i < game.wrds; i++){
                        if((localiza[0] == game.wrdsspot[i][0])  && (localiza[1] == game.wrdsspot[i][1]) &&
                        (localiza[2] == game.wrdsspot[i][2]) && (localiza[3] == game.wrdsspot[i][3])){
                            if(game.wrdsspot_ok[i][0] != -20){confirm = 2; break;} //Se a palvra ja estiver sido encontrada
                            else{ 
                                game.wrdsspot_ok[i][0] = (int) localiza[0];
                                game.wrdsspot_ok[i][1] = (int) localiza[1];
                                game.wrdsspot_ok[i][2] = (int) localiza[2];
                                game.wrdsspot_ok[i][3] = (int) localiza[3];
                                confirm = 1; break; //Tá tudo certo
                            }
                        }
                        confirm = 0; //Palavra não encontrada
                    }

                    if(confirm == 0){ //Se a coordenada estiver errada
                        printf("ERRO coordenada incorreta\n");
                        continue;
                    }

                    else if(confirm == 1){game.acertos++; break;} 

                    else{
                        printf("ERRO Essa palavra já foi encontrada\n");
                        continue;
                    }
                }
                
                else{continue;} //Se tiver algun erro
            }

            else{ //Caso seja uma opção invalida
                printf("ERRO escolha uma opção valida\n");
                continue;
            }
        }
    } 
}

void carrega_jogo(char arquivo[]){ //Essa função ira carregar um jogo salvo
    jogo game; //inicia o struct
    game.acertos = 0;

    char temp[4];
    FILE *txt = fopen(arquivo, "r"); //Abre o arquivo

    fscanf(txt, "%d %d\n", &game.m, &game.n); //Guarda

    for(int i = 0; i < game.m; i++){ //Pegando a matriz no arquivo
        for(int j = 0; j < game.n; j++){
            fscanf(txt, "%c ", &game.matriz[i][j]);
        }
    }

    fscanf(txt, "%d", &game.wrds); //Pega a quantidade de palavras
    

    for(int i = 0; i < game.wrds; i++){ //Pega as palavras e suas coordenadas
        fscanf(txt, "%s %c%c %c%c", game.palavras[i], &temp[0], &temp[1], &temp[2], &temp[3]);

        if(temp[0] != '-'){game.acertos++;} //Quantas palavras foram achadas

        game.wrdsspot_ok[i][0] = (int) (temp[0] - 65);
        game.wrdsspot_ok[i][1] = (int) (temp[1] - 65);
        game.wrdsspot_ok[i][2] = (int) (temp[2] - 65);
        game.wrdsspot_ok[i][3] = (int) (temp[3] - 65);

        game.wrdsspot[i][0] = game.wrdsspot_ok[i][0];
        game.wrdsspot[i][1] = game.wrdsspot_ok[i][1];
        game.wrdsspot[i][2] = game.wrdsspot_ok[i][2];
        game.wrdsspot[i][3] = game.wrdsspot_ok[i][3];
        
    }

    fclose(txt);

    game = resolve(game);
    play_jogo(game);
}

void cria_jogo(char arquvivo[], int nivel){ //Cria um novo jogo apartir do aquivo passado anteriormente
    jogo game; // Inicia o struct do jogo
    game.acertos = 0;

    FILE *txt = fopen(arquvivo, "r"); //Abre o arquivo

    fscanf(txt, "%d %d", &game.m, &game.n); //Pega as dimensões da matriz
    fscanf(txt, "%d", &game.wrds); //Pega a quantidade de palavras do arquivo

    for(int i = 0; i < game.wrds; i++){
        fscanf(txt, "%s", game.palavras[i]);//Pega as palavras do arquivo
        //Atribui inicialmente '-' para as corrdenadas encontradas
        game.wrdsspot_ok[i][0] = -20; //(char) + 65 = '-'
        game.wrdsspot_ok[i][1] = -20; //(char) + 65 = '-'
        game.wrdsspot_ok[i][2] = -20; //(char) + 65 = '-'
        game.wrdsspot_ok[i][3] = -20; //(char) + 65 = '-'
    }
    fclose(txt); //Fecha o arquivo

    game = gera_matriz(game, nivel); //Gera a matriz do jogo
    play_jogo(game); //Inicia o jogo
}