//Bibliotecas
#include <stdio.h>
#include <math.h>

//Variaveis globais
double c1, c2; 

int main(){
    //Entrada
    scanf("%lf", &c1);
    scanf("%lf", &c2);

    double h = sqrt(pow( c1, 2) + pow( c2, 2));//Processamento

    printf("A hipotenusa é %.2lf\n", h);//Saida
    return 0;
};