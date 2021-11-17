/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

/*
Questão 01
Faça um programa em C para efetua multiplicação de matrizes
*/

//Bibliotecas 
#include <stdio.h>

int main(){
    //Variaveis
    int m, p, q, n, soma = 0;

    //Dimensões da primeira matriz
    printf("Qual o numero de linhas e colunas da matriz A: "); scanf("%d %d", &m, &p);

    //Dimensões da segunda matriz
    printf("Qual o numero de linhas e colunas da matriz B: "); scanf("%d %d", &q, &n);

    //Erro
    while ((p != q) || (p > 10) || (m > 10) || (n > 10)){
        printf("ERRO: o numro de colunas da matriz A deve ser igual ao numero de linhas da matriz B e as dimensões não podem ser maior que 10\n");
        //Dimensões da primeira matriz
        printf("Qual o numero de linhas e colunas da matriz A: "); scanf("%d %d", &m, &p);
        //Dimensões da segunda matriz
        printf("Qual o numero de linhas e colunas da matriz B: "); scanf("%d %d", &q, &n);
    }
    
    //Matrizes
    int a[m][p], b[q][n], c[m][n];

    //Entradas das Matrizes A e B 
    printf("Digite os valores da matriz B\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < p; j++){
            printf("[%d][%d]: ", i, j); scanf("%d", &a[i][j]);
        }
    }

    printf("Digite os valores da matriz B\n");
    for (int i = 0; i < p; i++){
        for (int j = 0; j < n; j++){
            printf("[%d][%d]: ", i, j); scanf("%d", &b[i][j]);
        }
    }
    
    //Matriz produto
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < p; k++){
                soma += a[i][k] * b[k][j];
            }
            c[i][j] = soma;
            soma = 0;
        }
    }
    
    printf("\n");
    //Imprimir matriz do produto
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%5d", c[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}