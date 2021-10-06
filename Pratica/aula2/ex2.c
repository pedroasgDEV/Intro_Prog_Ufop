/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

/*
Questao 02
Faca um programa em C que le dois pontos P1 = (x1, y1) e P2= (x2, y2)
e em seguida calcula e imprime a distancia entre esses dois pontos.
*/

//Bibliotecas
#include <stdio.h>
#include <math.h>

//Prototipo da função que ira medir a distancia entre os dois pontos
double distancia(double x1, double y1, double x2, double y2);

int main(){
    //Variaveis
    double x1, y1, x2, y2;

    //Função que mede a distancia entre os dois pontos
    double distancia(double x1, double y1, double x2, double y2){
        return sqrt( pow(x2 - x1, 2) + pow(y2 - y1, 2) ); //Processamento 
    }

    //Entrada
    printf("Dê as cordenas de dois pontos de um plano cartesiano\n\n");
    printf("Cordenada x do ponto 1: "); scanf("%lf", &x1);
    printf("Cordenada y do ponto 1: "); scanf("%lf", &y1);
    printf("Cordenada x do ponto 2: "); scanf("%lf", &x2);
    printf("Cordenada y do ponto 2: "); scanf("%lf", &y2);

    //Saida
    printf("A distancia entre os dois pontos é %lf\n", distancia(x1, y1, x2, y2));
    return 0;
}