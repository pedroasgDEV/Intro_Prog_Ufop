
/*
QUESTÃO 3
Faça um programa que dado um número inteiro ímpar X(validar entrada),
imprima um losangulo de asteríscos de largura X.
*/

//Bibliotecas 
#include <stdio.h>

//Prototio das funções
void calcIntervalo(int *x, int *y, int *numb); //Função da soma dos numeros primos no intervalo
int primo(int i); //Função para verificar se é primo

int main(){
    //Variaveis
    int x, y; 
    int numb = 0;

    //Funções
    int primo(int i){ //Função para verificar se é primo
        int p = 2;
        while ( p < i){
            if (i % p == 0){//Se ele for divisivel por um numero diferente dele
                return 0; //se não for primo
            }
            p++;
        }
        return 1; //se for primo
    }

    void calcIntervalo(int *x, int *y, int *numb){ //Função da soma dos numeros primos no intervalo
        //Variaveis da função
        int i = *x + 1;

        ///Laço de repetição
        while(i <= *y){
            if (primo(i) == 1){ //Se o numero for primo
                *numb += i; //Soma dos primos
            }
            i++;
        }
    }

    //Entrada
    printf("Digite um numero para x: "); scanf("%d", &x); //Entrada do x
    printf("Digite um numero para y: "); scanf("%d", &y); //Entrada do y

    //Erro
    while (x >= y){ //Caso o x não for menor que o z
        printf("ERRO: o x deve ser menor que o y\n");
        printf("Digite um numero para x: "); scanf("%d", &x); //Entrada do x
        printf("Digite um numero para y: "); scanf("%d", &y); //Entrada do y
    }

    //Processamento
    calcIntervalo(&x, &y, &numb);
    
    //Saida
    printf(" A soma dos multiplos entre %d e %d é %d\n", x, y, numb);

    return 0;
}