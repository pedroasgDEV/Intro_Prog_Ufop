/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

//Bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Arquivos cabeçalho
#include "layouts.h"
#include "jogo.h"

void read(char arquivo[100]){
    system("clear"); //limpar tela
    FILE *txt = fopen(arquivo, "r"); //Abrindo arquivo a ser lido
    char temp[1000]; //string temporaria
    char resp;

    while (1){
        fgets(temp, 1000, txt);
        if(strcmp(temp, "#end") == 0){break;} //caso o arquivo tenha terminado
        printf("%s", temp);
    }
    getchar(); scanf("%c", &resp);
    fclose(txt);
}

void nivel_newgame(FILE *arquvivo){
    system("clear"); //Limpar tela
    char escolha[5];
    //Tela para definir a dificuldade
    printf("\n\nSelecione um nivel de difculdade\n\n");
    printf("1 - Facíl\n");
    printf("2 - Médio\n");
    printf("3 - Difícil\n\n");
    printf("Qualquer duvida vá à \"Instruções do jogo\" na tela inicial\n");
    printf("Para mudar a escolha de arquivo digite \"file\"\n");
    printf("Digite \"exit\" para sair do jogo ou \"main\" para voltar a tela inicial\n\n");
    printf("Escolha uma opção: "); scanf("%s", escolha);
    while(1){
        if(strcmp(escolha, "file") == 0){fclose(arquvivo); arq_newgame(); break;} //Caso o jogador queira mudar o arquivo
        else if(strcmp(escolha, "exit") == 0){fclose(arquvivo); printf("\nAté logo ;)\n\n"); exit(0);} //Caso o jogador queira sair
        else if(strcmp(escolha, "main") == 0){fclose(arquvivo); main_layout(); break;} //Caso o jogador queira sair
        else if(strcmp(escolha, "1") == 0){ cria_jogo(arquvivo, 1); break;} //Caso o jogador queira jogar no modo Facil
        else if(strcmp(escolha, "2") == 0){ cria_jogo(arquvivo, 2); break;} //Caso o jogador queira jogar no modo Médio
        else if(strcmp(escolha, "3") == 0){ cria_jogo(arquvivo, 3); break;} //Caso o jogador queira jogar no modo Dificil
        else{
            printf("ERRO!!! Escolha uma opção valida: "); scanf("%s", escolha);
        }
    }
}

void arq_newgame(){
    system("clear"); //limpar tela
    char arquivo[100];
    //Tela de novo jogo
    printf("\n\nNOVO JOGO\n\n");
    printf("Digite \"exit\" para sair do jogo ou \"main\" para voltar a tela inicial\n");
    printf("Qualquer duvida vá à \"Instruções do jogo\" na tela inicial\n\n");
    printf("OBS: Há alguns arquvios dicionario pre-montados na pasta \"dicionarios/\"\n\n");
    printf("Qual o arquivo dicionario que deseja usar? "); scanf("%s", arquivo); //Entrada do arquivo dicionario

    while(1){
        if(strcmp(arquivo, "exit") == 0){ printf("\nAté logo ;)\n\n"); exit(0);} //Caso o jogador queira sair
        else if(strcmp(arquivo, "main") == 0){ main_layout(); break;} //Caso o jogador queira sair
        else {
            FILE *txt = fopen(arquivo, "r");
            if(txt){//Verifica se o arquivo existe
                nivel_newgame(txt);
                break;
            }
            else{
                printf("ERRO arquivo não encontrado\n");
                printf("Qual o arquivo dicionario que deseja usar? "); scanf("%s", arquivo);
            }
        }
    }
}

void instructions(){
    system("clear"); //limpar tela
    char escolha[5];
    //Tela de instruções
    printf("\n\nINSTRUÇÕES\n");
    printf("O que deseja fazer:\n\n");
    printf("1 - Sobre o jogo\n");
    printf("2 - Sobre os niveis\n");
    printf("3 - Sobre os arquivos dicionario\n");
    printf("4 - Como jogar\n\n");
    printf("Digite \"exit\" para sair do jogo ou \"main\" para voltar a tela inicial\n\n");
    printf("Escolha uma opção: "); scanf("%s", escolha);

    while(1){
        if(strcmp(escolha, "exit") == 0){ printf("\nAté logo ;)\n\n"); exit(0);} //Caso o jogador queira sair
        else if(strcmp(escolha, "main") == 0){ main_layout(); break;} //Caso o jogador queira sair
        else if(strcmp(escolha, "1") == 0){read("files/jogo.txt");} //Caso o jogador queira começar um novo jogo
        else if(strcmp(escolha, "2") == 0){read("files/niveis.txt");}
        else if(strcmp(escolha, "3") == 0){read("files/dicionarios.txt");}
        else if(strcmp(escolha, "4") == 0){read("files/conojogar.txt");}
        else{printf("ERRO: Escolha uma opção valida: "); scanf("%s", escolha); continue;}
        system("clear"); //limpar tela
        printf("\n\nINSTRUÇÕES\n");
        printf("O que deseja fazer:\n\n");
        printf("1 - Sobre o jogo\n");
        printf("2 - Sobre os niveis\n");
        printf("3 - Sobre os arquivos dicionario\n");
        printf("4 - Como jogar\n\n");
        printf("Digite \"exit\" para sair do jogo ou \"main\" para voltar a tela inicial\n\n");
        printf("Escolha uma opção: "); scanf("%s", escolha);
    }
}

void main_layout(){
    system("clear"); //limpar tela
    char escolha[5];
    //Tela inicial
    printf("\n\nOla :) Bem vindo ao jogo de caça palavras\n");
    printf("O que deseja fazer:\n\n");
    printf("1 - Começar um novo jogo\n");   
    printf("2 - Continuar um jogo anterior\n");
    printf("3 - Instruções do jogo\n\n");
    printf("Digite \"exit\" para sair do jogo\n\n");
    printf("Escolha uma opção: "); scanf("%s", escolha);
    
    while(1){
        if(strcmp(escolha, "exit") == 0){ printf("\nAté logo ;)\n\n"); exit(0);} //Caso o jogador queira sair
        else if(strcmp(escolha, "1") == 0){arq_newgame(); break;} //Caso o jogador queira começar um novo jogo
        else if(strcmp(escolha, "2") == 0){/*continue_game();*/ break;}
        else if(strcmp(escolha, "3") == 0){instructions(); break;}
        else{printf("ERRO: Escolha uma opção valida: "); scanf("%s", escolha);}
    }
}