//Bibliotecas
#include <stdio.h> 

//variaveis globais
int x, y, z;

int main(){

    scanf("%d", &x);//função de leitura
    scanf("%d", &y);//função de leitura
    scanf("%d", &z);//função de leitura

    printf("x=%d, y=%d, z=%d", x, y, z);//resultado leitura

    printf(" o resultado é %d\n", (x * x  * x) + (y * y) + (x * y * z));//esultado calculo
    return 0;
};
