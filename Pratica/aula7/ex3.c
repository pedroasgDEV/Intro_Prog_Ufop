/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

/*
Questão 03
Faça um programa que leia um número inteiro n ≤ 500 digitado pelo usuário. Gere 100.000 inteiros
aleatórios no intervalo de 1 a n e os armazene em um vetor. Use um vetor A para manter a contagem 
da frequência de ocorrência de cada inteiro (ou seja, use A[1] para controlar o número de ocorrências
do inteiro 1, A[2] para o inteiro 2 e assim por diante). Implemente também uma função para Imprimir 
o número de vezes que cada inteiro de 1 a n foi gerado.
*/

//Bibliotecas 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Tamanho do vetor
#define t_vetor 100000

//Prototipo da função que imprime a contagem
void contagem(int a[], int n);

//Função que imprime a contagem
void contagem(int a[], int n){   
    for(int i = 1; i <= n; i++){printf("\"%d\": %d; ", i, a[i]);} 
    printf("\n");
}

int main(){
    //Semente do rand
    srand(time(NULL));
    
    //Variaveis
    int n, random[t_vetor];

    //Entrada
    printf("Digite um numero: "); scanf("%d", &n);

    //Erro
    while((n <= 0) || (n >500)){
        printf("ERRO: A quantidade digitada deve ser entre 1 e 500\n");
        printf("Digite um numero: "); scanf("%d", &n);
    }

    //Vetor contagem
        int a[n + 1]; for (int i = 0; i < n + 1; i ++){a[i] = 0;}

    //Vetor com numeros aleatorios e contagem
    for (int i = 0; i < t_vetor; i ++){
        random[i] = 1 + (rand() % n);//Grava os numeros aleatorios no vetor
        a[random[i]]++;//Faz a contagem da frequencia
    }
    
    //Saida
    contagem(a, n);

    return 0;
}