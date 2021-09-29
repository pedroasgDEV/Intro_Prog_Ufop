//Bibliotecas 
#include <stdio.h>

//variaveis globais
float a , b, c, d, e;

int main(){
    //entrada 
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    scanf("%f", &d);
    scanf("%f", &e);

    float calc = (a * a * a) * ( (b + c)/d + e); //processamento

    printf("o resultado é %.0f\n", calc);
    return 0;
};