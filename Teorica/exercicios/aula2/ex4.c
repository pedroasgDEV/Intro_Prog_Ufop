//Bibliotecas 
#include <stdio.h>

//variaveis globais
int x1, x2, x3;

int main(){
    //entrada 
    scanf("%d", &x1);
    scanf("%d", &x2);
    scanf("%d", &x3);

    int calc = ( (x1 + 3) * (x1 + 3) * (x1 + 3) * (x1 + 3) ) + ( (x2 * x3) * (x2 * x3) * (x2 * x3) ); //processamento

    printf("o resultado é %.2d\n", calc);
    return 0;
};