/*
Exercício 2:
Dado um número x, faça um programa que leia este número e em uma
função calcule x² E x³. Os resultados devem ser impressos dentro da função
principal main().
*/

//Bibliotecas 
#include <stdio.h>
#include <math.h>

//Prototio das funções
void calcPotencia(int x, int *quad, int *cubo); //Função de potencia

//Funções
void calcPotencia(int x, int *quad, int *cubo){ //Função de potencia
    *quad = pow(x, 2); //Calcula Quadrado
    *cubo = pow(x, 3); //Calcula Cubo
}

int main(){
    //Variaveis
    int x, quad, cubo;

    //Entrada
    printf("Digite um numero para x: "); scanf("%d", &x); //Entrada do x

    //Processamento
    calcPotencia(x, &quad, &cubo);

    //Saida
    printf("O quadrado de %d é %d\n", x, quad);
    printf("O cubo de %d é %d\n", x, cubo);

    return 0;
}