//Bibliotecas
#include <stdio.h>
#include <string.h>

//Tamanho array
#define n 10

int main(){
    //Strings
    int a[n], b[n], soma = 0;

    //Entradas do primeiro vetor
    for(int i = 0; i < n ; i++){
        printf("Digite o valor da posição %d do primeiro vetor: ", i);
        scanf("%d", &a[i]);
    }

    //Entradas do segundo vetor
    for(int i = 0; i < n ; i++){
        printf("Digite  um numero para a posição %d do segundo vetor: ", i);
        scanf("%d", &b[i]);
    }

    //Processamento
    for(int i = 0; i < n ; i++){
        soma += a[i] * b[i];
    }

    printf("%d\n", soma);
    return 0;
}