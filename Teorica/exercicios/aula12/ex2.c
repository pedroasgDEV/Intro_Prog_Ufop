//Bibliotecas 
#include <stdio.h>

//tamanho arrays
#define m 10
#define n m

int main(){
    //Variaveis
    int x[m][n], maior = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("Digite o valor da posiçaõ %d %d da matriz: ", i, j); scanf("%d", &x[i][j]);
            if(x[j][i] > maior){maior = x[i][j];}//Verifica qual o maior valor
        }
    }
    
    //imprimir matriz
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%5d ", x[i][j]);
        }
        printf("\n");
    }

    printf("O maior valor é %d\n", maior);//Imprime o maior valor

    //Imprime a diagonal primaria
    for(int i = 0; i < m; i++){
        printf("%d ", x[i][i]);
    }
    printf("\n");

    //Imprime a diagonal secundaria
    for(int i = 0, j = n - 1; i < m; i++, j--){
        printf("%d ", x[i][j]);
    }
    printf("\n");

    return 0;
}