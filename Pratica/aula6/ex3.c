/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

/*
Questão 03
Desde a aula de ontem, Bart Simpson continua tentando aprender a jogar xadrez. Ele aprendeu
como uma Torre se move, mas tem dificuldade em saber para qual direção ele pode mover um Bispo.
Sabendo que um tabuleiro de xadrez é composto por 8 linhas e 8 colunas, e que o Bispo se move nas
diagonais
*/

//Bibliotecas 
#include <stdio.h>

//Prototio das função que simula os movimentos do bispo
void movBispo(int coluna, int linha); 

//Funções
void movBispo(int coluna, int linha){ //Função que simula os movimentos do bispo
    //Variaveis da função
    int x = 1;
    int y = 1;

    //Layout da parte de cima
    printf("\n");
    printf("     1  2  3  4  5  6  7  8\n");
    printf("   -------------------------\n");
    
    //Laço de repetição para simular os movimentos do bispo
    while(y <= 8){ //Laço da linha
        printf("%d | ", y);// //Layout da parte lateral

        while (x <= 8){ //Laço da coluna
            if((x == coluna - (y - linha)) || (x == coluna + (y - linha))){ //Verifica se nessa posição o bispo alcança
                if((x == coluna) && (y == linha)){printf(" o ");}
                else{printf(" x ");}
            }
            else{
                printf(" - ");
            }

            x++;
        }
        x = 1;
        printf("\n"); 
        y++;
    }
    printf("\n");
}

int main(){
    //Variaveis
    int coluna, linha;

    //Entrada
    printf("Movimentos de um Bispo no xadrez!\n");
    printf("Digite a linha em que o Bispo se encontra: "); scanf("%d", &linha); //Entrada da linha que o bispo está
    printf("Digite a coluna em que o Bispo se encontra: "); scanf("%d", &coluna); //Entrada da coluna que o bispo está

    //Erro
    while ((linha <= 0) || (coluna <= 0) || (linha > 8) || (coluna > 8)){ //Caso algum valor seja menor que 0 ou maior que 8
        printf("ERRO: os valores inseridos não podem ser maiores que 8 e devem ser maiores que 0\n");
        printf("Movimentos de um Bispo no xadrez!\n");
        printf("Digite a linha em que o Bispo se encontra: "); scanf("%d", &linha); //Entrada da linha que o bispo está
        printf("Digite a coluna em que o Bispo se encontra: "); scanf("%d", &coluna); //Entrada da coluna que o bispo está
    }

    //Processamento
    movBispo(coluna, linha);

    return 0;
}