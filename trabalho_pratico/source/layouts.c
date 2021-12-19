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
#include "functions.h"

void instructions(){
    char escolha[5];
    //Tela de instruções
    printf("\n\nINSTRUÇÕES\n");
    printf("O que deseja fazer:\n\n\n");
    printf("1 - Sobre o jogo\n");
    printf("2 - Sobre os niveis\n");
    printf("3 - Sobre os arquivos dicionario\n");
    printf("Digite \"sair\" para sair do jogo ou \"init\" para voltar a tela inicial\n\n\n");
    printf("Escolha uma opção: "); scanf("%s", escolha);

    while(1){
        if(strcmp(escolha, "sair") == 0){ printf("Até logo ;)\n\n"); exit(0);} //Caso o jogador queira sair
        else if(strcmp(escolha, "init") == 0){ main_layout(); break;} //Caso o jogador queira sair
        else if(strcmp(escolha, "1") == 0){read("files/jogo.txt");} //Caso o jogador queira começar um novo jogo
        else if(strcmp(escolha, "2") == 0){read("files/niveis.txt");}
        else if(strcmp(escolha, "3") == 0){read("files/dicionarios.txt");}
        else{printf("ERRO: Escolha uma opção valida: "); scanf("%s", escolha); continue;}
        printf("\n\nINSTRUÇÕES\n");
        printf("O que deseja fazer:\n\n\n");
        printf("1 - Sobre o jogo\n");
        printf("2 - Sobre os niveis\n");
        printf("3 - Sobre os arquivos dicionario\n");
        printf("Digite \"sair\" para sair do jogo ou \"init\" para voltar a tela inicial\n\n\n");
        printf("Escolha uma opção: "); scanf("%s", escolha);
    }

}

void main_layout(){
    char escolha[5];
    //Tela inicial
    printf("\n\nOla :) Bem vindo ao jogo de caça palavras\n");
    printf("O que deseja fazer:\n\n\n");
    printf("1 - Começar um novo jogo\n");   
    printf("2 - Continuar um jogo anterior\n");
    printf("3 - Instruções do jogo\n");
    printf("Digite \"sair\" para sair do jogo\n\n\n");
    printf("Escolha uma opção: "); scanf("%s", escolha);
    
    while(1){
        if(strcmp(escolha, "sair") == 0){ printf("Até logo ;)\n\n"); exit(0);} //Caso o jogador queira sair
        else if(strcmp(escolha, "1") == 0){/*new_game();*/ break;} //Caso o jogador queira começar um novo jogo
        else if(strcmp(escolha, "2") == 0){/*continue_game();*/ break;}
        else if(strcmp(escolha, "3") == 0){instructions(); break;}
        else{printf("ERRO: Escolha uma opção valida: "); scanf("%s", escolha);}
    }
}