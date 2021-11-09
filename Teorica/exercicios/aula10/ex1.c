//Bibliotecas
#include <stdio.h>

//Prototio de função
int maior(int vetor[], int tamanho);

//função
int maior(int vetor[], int tamanho){
    int maior = 0;
    for(int i = 0; i < tamanho; i++){
        if(vetor[i] > maior){maior=vetor[i];}
    }
    return maior;
}

int main(){
    //tamanho do array
    int tamanho;
    printf("Quantos numeros?: "); scanf("%d", &tamanho);

    //valores do array
    int vetor[tamanho];
    for(int i = 0; i < tamanho; i++){
        printf("Digite o numero %d: ", i); scanf("%d", &vetor[i]); //entrada do array
    }

    //Saida
    printf("O maior numero é %d\n", maior(vetor, tamanho));

    return 0;
}