//Bibliotecas 
#include <stdio.h>

//Prototipo da função de media harmonica
double mediaHarmonica(int n);

int main(){
    //Variaveis
    int n;
    
    //Função de media harmonica
    double mediaHarmonica(int n){
        //Variaveis da função
        double soma, i;
        int p = 0;

        while(p < n){//Looping da soma
            printf(" Numero %d: ", p + 1); scanf("%lf", &i); //Entrada dos numeros que iram ser somados
            soma += 1 / i;
            p++;
        }

        return n/soma;//Retorno da media harmonica da soma dos numeros 
    }

    //Entrada
    printf("Quantos números você quer digitar: "); scanf("%d", &n); //Entrada da quantidae de numeros somados
    
    //Erro
    while (n <= 0){
        printf("ERRO: digite uma quantidade de numeros positiva e maior que 0\n");
        printf("Quantos números você quer digitar:"); scanf("%d", &n); //Entrada da quantidae de numeros somados
    }
    
    //Saida
    printf("A media harmonica dos numeros é %.2lf\n", mediaHarmonica(n));// Saida da media harmonica

    return 0;
}