//Bibliotecas
#include <stdio.h>
#include <math.h>

//Variaveis globais
double a, h; 

int main(){
    //Entrada
    scanf("%lf", &a);
    scanf("%lf", &h);
    
    //Processamento
    double c1 = cos(a) * h;
    double c2 = sin(a) * h;

    printf(" o cateto 1 é %.2lf e o cateto 2 é %.2lf\n ", c1, c2);//Saida
    return 0;
};