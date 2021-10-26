#include <stdio.h>
#include <math.h>

double imc(double peso, double altura);

double imc(double peso, double altura){
    return peso/pow(altura, 2);
}

int main(){
    double peso, altura;
    printf("Digite seu peso e sua altura: "); scanf("%lf %lf", &peso, &altura);
    printf("O IMC: %lf\n", imc(peso, altura));
    return 0;
}