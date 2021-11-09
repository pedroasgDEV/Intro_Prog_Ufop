//Bibliotecas
#include <stdio.h>

//Prototio de função
double media(double *vetor, int tamanho);

//função
double media(double *vetor, int tamanho){
    double soma = 0;
    for(int i = 0; i < tamanho; i++){
        soma += *(vetor + i);
    }
    return soma/tamanho;
}

int main(){
    //tamanho do array
    int tamanho;
    printf("Quantos numeros?: "); scanf("%d", &tamanho);

    //valores do array
    double vetor[tamanho];
    for(int i = 0; i < tamanho; i++){
        printf("Digite o numero %d: ", i); scanf("%lf", &vetor[i]); //entrada do array
    }

    //Saida
    printf("A media é %.2lf\n", media(vetor, tamanho));

    return 0;
}