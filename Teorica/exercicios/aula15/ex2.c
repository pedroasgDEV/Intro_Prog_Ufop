//Bibliotecas 
#include <stdio.h>
#include <stdlib.h>

//Prototipo de função
int **trasnsposta(int **v, int n, int m);

//Função
int **trasnsposta(int **v, int n, int m){
    //matriz temporario
    int **temp = malloc(n * sizeof(int));
  
    //Preneche o vetor temporario, com o inverso do vetor parametro
    for(int i = 0; i < n; i++){
        temp[i] = malloc(m * sizeof(int*));
        for(int j = 0; j < m; j++){
            temp[i][j] = v[j][i];
        }
    }
    
    return temp;
}

int main(){
    //Variaveis
    int n, m;

    //Define a dimensão do vetor
    printf("Digite o tamanho do vetor (n x m): "); scanf("%d %d", &n, &m);
    int **v = malloc(n * sizeof(int*));

    //Preenche o vetor
    printf("Digite os dados do vetor: \n");
    
    for(int i = 0; i < n; i++){
        v[i] = malloc(m * sizeof(int));
        for(int j = 0; j < m; j++){
            printf("[%d][%d]: ", i, j); scanf("%d", &v[i][j]);
        }       
    }

    //Processamento
    int **a = trasnsposta(v, n, m);

    //Saida
    printf("Vetor trasposto: ");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
        free(v[i]);
        free(a[i]);
    }
    
    free(v);
    free(a);

    return 0;
}