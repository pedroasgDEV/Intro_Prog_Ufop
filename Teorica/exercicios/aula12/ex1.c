//Bibliotecas 
#include <stdio.h>

//tamanho arrays
#define m 3
#define n 3

int main(){
    int soma[m][n], str1[m][n], srt2[m][n];
    //adiciona valores
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            str1[i][j] = (j + 1) * (i + 1);
            srt2[i][j] = str1[i][j] * 2;
        }
    }
    //Soma as duas matrizes
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            soma[i][j] = str1[i][j] + srt2[i][j];
        }
    }

    //Imprime a matriz som
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", soma[i][j]);
        }
    }
    printf("\n");
    return 0;
}