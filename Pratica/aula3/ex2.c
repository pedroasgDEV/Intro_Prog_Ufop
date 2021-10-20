/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

/*
Questão 02
Crie um aplicativo que calcula as raı́zes de uma equação do 2o grau.
*/

//Bibliotecas
#include <stdio.h>
#include <math.h>

//Prototipo da função que ira calcular as raizes de equação do 2o grau
void calculaRaizes(double a, double b, double c, double *delta, double *x_1, double *x_2);

//Função que ira calcular as raizes de equação do 2o grau
void calculaRaizes(double a, double b, double c, double *delta, double *x_1, double *x_2){
    *delta = pow(b, 2) - (4 * a * c); //Calculo do delta
    *x_1 = (-b + sqrt(*delta)) / (2 * a); //Calculo da primeira raiz
    *x_2 = (-b - sqrt(*delta)) / (2 * a); //Calculo da segunda raiz
}

int main(){
    //Variaveis
    double a, b, c, delta, x_1, x_2;

    //Entrada
    printf("Data uma equação de segundo grau \"a * (x)^2 + b * x + c = 0\" \n");
    printf("Digite um valor para a: "); scanf("%lf", &a); //Entrada do valor de a
    printf("Digite um valor para b: "); scanf("%lf", &b); //Entrada do valor de b
    printf("Digite um valor para c: "); scanf("%lf", &c); //Entrada do valor de c

    //Processamento
    calculaRaizes(a, b, c, &delta, &x_1, &x_2);

    //Saida
    printf("O valor do delta é: %.2lf\n", delta); //Saida do valor do Delta

    //Verificação de se há raizes
    if (delta >= 0){ //Se há raizes
        printf("1: Delta maior ou igual a zero, há raizes possiveis\n");
        
        //Verificação da quantidade de raizes
        if (delta == 0){ //Se só há uma raiz possivel
            printf("O valor da unica raiz possivel é: %.2lf\n", x_1); //Saida do valor da primeira raiz
        }
        else{ //Se há duas raizes possiveis
            printf("O valor da primeira raiz é: %.2lf\n", x_1); //Saida do valor da primeira raiz
            printf("O valor da segunda raiz é: %.2lf\n", x_2); //Saida do valor da segunda raiz
        }
    }
    else{ //Se não há raizes
        printf("0: Delta menor que zero, não há raizes possiveis\n");
    }
    return 0;
}