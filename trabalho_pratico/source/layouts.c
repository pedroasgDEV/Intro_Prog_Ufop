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

//Prototipo de funções
void read(char arquivo[100]);
int verifica_arq(FILE *txt);

int verifica_arq(FILE *txt){ //Função que verifica se o arquivo segue as condições de bom funcionamento
    int m, n, qnt_wrds;
    fscanf(txt, "%d %d\n%d", &m, &n, &qnt_wrds);

    if((m > 26) || (n > 26)){ //Caso as dimenções do caça palavras utrapassem 26
        printf("\nERRO Alguma das dimenções do caça palavras utrapassa 26\n\n");
        return 1;
    } 
    
    if((qnt_wrds > m) || (qnt_wrds > n)){ //Caso a quantidade de palvras ultrapasse alguma dimenção
        printf("\nERRO A quantidade de palvras ultrapassa alguma das dimenções\n\n");
        return 1;
    } 
    
    char palavra[qnt_wrds][26];
    int tamanho;

    for(int i = 0; i < qnt_wrds; i++){
        fscanf(txt, "%s", palavra[i]);
        tamanho = strlen(palavra[i]);

        if((tamanho > m) || (tamanho > n)){ //Caso alguma palavra for maior que alguma dimenção
            printf("\nERRO Há uma palavra que é maior que alguma das dimenções\n\n");
            return 1;
        } 
        
        for(int j = 0; j < tamanho; j++){
            if(((palavra[i][j] < 'A') || (palavra[i][j] > 'Z')) &&
               ((palavra[i][j] < 'a') || (palavra[i][j] > 'z'))){
                printf("\nERRO Em alguma palavra há um caracter que não é letra\n");
                printf("Ou a quantidades de palvras é maior que a quantidade de palavras presentes\n\n");
                return 1;
            } //Caso haja algum caracter que não seja uma letra na palvra 
            //ou a quantidades de palvras é maior que a quantidade de palavras presentes
        }
    }

    return 0; //Nenhum erro encontrado
}

void read(char arquivo[100]){ //Função le um arquivo txt e imprime
    system(limpa); //limpar tela
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

void nivel_newgame(char arquvivo[]){ //Função pega o nivel do jogo
    system(limpa); //Limpar tela
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
        if(strcmp(escolha, "file") == 0){arq_newgame(); break;} //Caso o jogador queira mudar o arquivo
        else if(strcmp(escolha, "exit") == 0){printf("\nAté logo ;)\n\n"); exit(0);} //Caso o jogador queira sair
        else if(strcmp(escolha, "main") == 0){main_layout(); break;} //Caso o jogador queira sair
        else if(strcmp(escolha, "1") == 0){ cria_jogo(arquvivo, 1); break;} //Caso o jogador queira jogar no modo Facil
        else if(strcmp(escolha, "2") == 0){ cria_jogo(arquvivo, 2); break;} //Caso o jogador queira jogar no modo Médio
        else if(strcmp(escolha, "3") == 0){ cria_jogo(arquvivo, 3); break;} //Caso o jogador queira jogar no modo Dificil
        else{
            printf("ERRO!!! Escolha uma opção valida: "); scanf("%s", escolha);
        }
    }
}

void arq_newgame(){ //Função pega o arquivo dicionario e verifica se ele exite
    system(limpa); //limpar tela
    int confim; 
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
            FILE *txt = fopen(arquivo, "r"); //Abre o arquivo
            if(txt){//Verifica se o arquivo existe
                confim = verifica_arq(txt); //Testa para ver se esta tudo certo
                fclose(txt);//fecha o arquivo
                
                if(confim == 0){nivel_newgame(arquivo); break;} //Ta tudo certo
                
                //Possiveis erros
                else{printf("Qual o arquivo dicionario que deseja usar? "); scanf("%s", arquivo);}
            }
            else{
                printf("ERRO arquivo não encontrado\n");
                printf("Qual o arquivo dicionario que deseja usar? "); scanf("%s", arquivo);
            }
        }
    }
}

void instructions(){ //Função das instruções do jogo
    system(limpa); //limpar tela
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
        system(limpa); //limpar tela
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

void main_layout(){ //Tela inicial do jogo
    system(limpa); //limpar tela
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