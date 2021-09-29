//Bibliotecas
#include <stdio.h>
#include <math.h>

//Variaveis globais
double ax, ay, bx, by;

int main(){
    //Entrada
    scanf("%lf %lf", &ax, &ay);
    scanf("%lf %lf", &bx, &by);

    double d = sqrt(pow( ax - bx, 2) + pow( ay - by, 2));//Processamento

    printf("A distancia é %.2lf\n", d);//Saida
    return 0;
};