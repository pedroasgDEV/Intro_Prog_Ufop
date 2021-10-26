#include <stdio.h>
#include <math.h>
int main(){
    double peso, altura, IMC;
    printf("Digite seu peso em KG e sua altura em metros: ");
    scanf("%lf %lf", &peso, &altura);
    IMC = peso/pow(altura,2);
    if (IMC < 20){printf("IMC abaixo do normal");}
    else if (IMC < 25){printf("IMC normal");}
    else if (IMC < 40){printf("IMC indica sobrepeso");}
    else {printf("IMC indica opseidade morbida");}
    printf("\n");
    return 0;
}