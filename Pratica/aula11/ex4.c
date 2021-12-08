/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

//Bibliotecas 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Prototipo das funções

// Aloca espaço para uma matriz m x n. Se não for possı́vel criar a matriz, retorna NULL
int** cria_matriz(int n, int *menor);

// Multiplica 2 matrizes.
int verifica(int **A, int n, int menor);

// Libera o espaço utilizado por uma matriz.
void desaloca_matriz(int** A, int n);

//Funções

// Aloca espaço para uma matriz m x n. Se não for possı́vel criar a matriz, retorna NULL
int** cria_matriz(int n, int *menor){
    //Caso não seja uma matriz
    if(n == 0){ return NULL; }

    //matriz temporaria
    int **temp = malloc(n * sizeof(int*));
    

    //Entrada do vetor temporario
    printf("Digite os valores da matriz n x n:\n");
    for(int i = 0; i < n; i++){
        temp[i] = malloc(n * sizeof(int));
        for(int j = 0; j < n; j++){
            scanf("%d", &temp[i][j]);
            if(temp[i][j] < *menor){ *menor = temp[i][j];}
        }
    }
    return temp;
}

// Multiplica 2 matrizes.
int verifica(int **A, int n, int menor){
    //Soma das coluna, linhas e diagonais
    int soma = (n + pow(n, 3)) / 2 + (menor - 1) * n;

    //Variaveis da função
    int som_ln, som_cl, som_dig1 = 0, som_dig2 = 0;

    for(int i = 0; i < n; i++){
        som_ln = 0;
        som_cl = 0; 
        
        for (int j = 0; j < n; j++){
            som_ln += A[i][j];//soma os valores em cada linha
            som_cl += A[j][i];//soma os valores em cada coluna
        }

        if((som_ln != soma) || (som_cl != soma)){ return 0;} //Verificação pela soma em cada linha e coluna

        som_dig1 += A[i][i]; //Soma os valores na diagonal primaria
        som_dig2 += A[i][(n - 1) - i]; //Soma os valores na diagonal secundaria
    }
    if((som_dig1 != soma) || (som_dig2 != soma)){ return 0;} //Verificação pela soma das diagonais
    
    return 1;//Se for um quadrado magico
}

// Libera o espaço utilizado por uma matriz.
void desaloca_matriz(int** A, int n){
    for(int i = 0; i < n; i++){
        free(A[i]);
    }

    free(A);
}

int main(){
    //Variaveis
    int n, menor = 32767;

    //Define a dimensão da matriz
    printf("Digite o valor de n: "); scanf("%d", &n);
    int **A = cria_matriz(n, &menor);
    
    //ERRO
    while(A == NULL){
        printf("ERRO!!!! n == 0 : Digite o valor de n: "); scanf("%d", &n);
        A = cria_matriz(n, &menor);
    }
    
    //Saida
    switch(verifica(A, n, menor)){
        case 0: //Se não for um quadrado magico
            printf("\nEsta matriz não é um quadrado mágico! \n");
            break;
        
        case 1: //Se for um quadrado magico
            printf("\nEsta matriz é um quadrado mágico! \n");
            break;
    }
    
    //Libera as matrizes
    desaloca_matriz(A, n);

    return 0;
}