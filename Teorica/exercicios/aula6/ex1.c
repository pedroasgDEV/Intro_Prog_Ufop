//Bibliotecas 
#include <stdio.h>

//Variaveis globais
double C;

//Funções
//Funcão de transformação de celsius para Fahrenheit
double Fahrenheit(double C){
    return 1.8 * C + 32;
}

int main(){
    
    //Entrada
    printf("digite uma temperatura em celsius: "); scanf("%lf", &C);
    
    //Saida
    printf("A temperatura %.2lf°C é equivalente a %.2lf°F\n", C, Fahrenheit(C));

    return 0;
}
