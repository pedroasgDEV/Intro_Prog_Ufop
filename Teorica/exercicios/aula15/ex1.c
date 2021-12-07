//Bibliotecas 
#include <stdio.h>
#include <stdlib.h>

//Prototipo de função
int *inverso(int *v, int n);

//Função
int *inverso(int *v, int n){
    //vetor temporario
    int *temp = malloc(n * sizeof(int));
    
    //Preneche o vetor temporario, com o inverso do vetor parametro
    for(int i = 0; i < n; i++){
        temp[i] = v[n - (i + 1)];
    }
    
    return temp;
}

int main(){
    //Variaveis
    int n;

    //Define a dimensão do vetor
    printf("Digite o tamanho do vetor: "); scanf("%d", &n);
    int *v = malloc(n * sizeof(int));

    //Preenche o vetor
    printf("Digite os dados do vetor: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    //Processamento
    int *a = inverso(v, n);

    //Saida
    printf("Vetor invertido: ");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    free(v);
    free(a);

    return 0;
}