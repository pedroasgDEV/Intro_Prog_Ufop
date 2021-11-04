//Bibliotecas 
#include <stdio.h>

int main(){
    //Variaveis
    int x, n, m;

    printf("Digite a quota mensal em megabytes entre 1 e 100: "); scanf("%d", &x);
    while ((x <= 0) || (x > 100)){
        printf("ERRO: Digite novamente\n");
        printf("Digite a quota mensal em megabytes entre 1 e 100: "); scanf("%d", &x);
    }
    int p = x;
    printf("Digite o número de meses entre 1 e 100: "); scanf("%d", &n);
    while ((n <= 0) || (n > 100)){
        printf("ERRO: Digite novamente\n");
        printf("Digite o número de meses entre 1 e 100: "); scanf("%d", &n);
    }
    
    for (int i = 0; i < n; i++){
        printf("Digite a quantidade de megabytes que João usou no mes %d: ", i + 1); scanf("%d", &m);
        while ((m <= 0) || (m > x)){
            printf("ERRO: Digite novamente\n");
            printf("Digite a quantidade de megabytes que João usou no mes %d: ", i + 1); scanf("%d", &m);
        }
        x = p + x - m; 
    }
    printf("João tem %d megabytes para o proximo mes\n", x);
}