/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

/*
Questão 01
Crie um algoritmo que calcule, armazene em um vetor e imprima os 10 primeiros números {F 1 , F 2 ,
F 3 , F 4 , F 5 , . . . , F 10 } da série de Fibonacci
*/

//Bibliotecas 
#include <stdio.h>

//Tamanho do vetor
#define t_vetor 10

int main(){
    //Variaveis
    int F[t_vetor] = {1,1};

    //Entrada
    for (int i = 2; i < t_vetor; i++){
        F[i] = F[i-1] + F[i-2];
    }

    //Saida
    for (int i = 0; i < t_vetor; i++){printf("%d ", F[i]);}
    printf("\n");

    return 0;
}