/*
QUESTÃO 3
Faça um programa que dado um número inteiro ímpar X(validar entrada),
imprima um losangulo de asteríscos de largura X.
*/

//Bibliotecas 
#include <stdio.h>

//Prototio das funções
void calcPrisma(int *x); //Função de criar um prisma

int main(){
    //Variaveis
    int x;

    //Funções
    void calcPrisma(int *x){ //Função de criar um prisma
        //Variaveis da função
        int i = 1;
        int p = 0;
        int c = 0;
        int espacos = (*x - 1) / 2; //espaços para dar forma ao losango

        //Saida
        //Laço de repetição para fazer o losango
        while(i <= *x){ //Parte de cima do losango
            if ((i % 2 != 0) || (i == 1)){
                while(c < espacos){
                    printf("   ");
                    c++;
                }
                c = 0;
                while(p < i){
                    printf(" * ");
                    p++;
                }
                p = 0;
                espacos--;
                printf("\n");  
            }
            i++;
        }
        i -= 2;
        espacos += 2;
        while(i > 0){ //Parte de baixo do losango
            if ((i % 2 != 0) || (i == 1)){
                while(c < espacos){
                    printf("   ");
                    c++;
                }
                c = 0;
                while(p < i){
                    printf(" * ");
                    p++;
                }
                p = 0;
                espacos++;
                printf("\n");  
            }
            i--;
        }
    }
    //Entrada
    printf("Digite um numero para x: "); scanf("%d", &x); //Entrada do x

    //Erro
    while (x % 2 == 0 ){ //Caso o x for par
        printf("ERRO: x deve ser impar\n");
        printf("Digite um numero para x: "); scanf("%d", &x); //Entrada do x
    }

    //Processamento
    calcPrisma(&x);

    return 0;
}