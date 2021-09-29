/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

/*
Questão 03
Escreva um programa que leia de 3 números inteiros. Em seguida, o programa deve verificar qual dos
valores é o menor, o intermediário e o maior.
Supondo as entradas 23, 11, 31, a saı́da do programa seria:
Menor: 11
Intermediario: 23
Maior: 31
*/

//Bibliotecas
#include <stdio.h>

//Variaveis Globais
int numero_1, numero_2, numero_3;

int main(){

    //Entrada
    printf("Digite um numero: ");
    scanf("%d", &numero_1);
    printf("Digite outro numero: ");
    scanf("%d", &numero_2);
    printf("Digite mais outro numero: ");
    scanf("%d", &numero_3);

    //Processamento
    //Organizando os numeros
    
    //Probabilidade 1
    if((numero_1 > numero_2) && (numero_1 > numero_3) && (numero_2 > numero_3)){
        printf("Menor: \"%d\"\n", numero_3);//Saida
        printf("Intermediario: \"%d\"\n", numero_2);//Saida
        printf("Maior: \"%d\"\n", numero_1);//Saida
    }
    
    //Probabilidade 2
    if((numero_1 > numero_2) && (numero_1 > numero_3) && (numero_2 < numero_3)){
        printf("Menor: \"%d\"\n", numero_2);//Saida
        printf("Intermediario: \"%d\"\n", numero_3);//Saida
        printf("Maior: \"%d\"\n", numero_1);//Saida
    }
    
    //Probabilidade 3
    if((numero_1 > numero_2) && (numero_1 < numero_3)){
        printf("Menor: \"%d\"\n", numero_2);//Saida
        printf("Intermediario: \"%d\"\n", numero_1);//Saida
        printf("Maior: \"%d\"\n", numero_3);//Saida
    }
    
    //Probabilidade 4
    if((numero_1 < numero_2) && (numero_1 > numero_3)){
        printf("Menor: \"%d\"\n", numero_3);//Saida
        printf("Intermediario: \"%d\"\n", numero_1);//Saida
        printf("Maior: \"%d\"\n", numero_2);//Saida
    }
    
    //Probabilidade 5
    if((numero_1 < numero_2) && (numero_1 < numero_3) && (numero_2 > numero_3)){
        printf("Menor: \"%d\"\n", numero_1);//Saida
        printf("Intermediario: \"%d\"\n", numero_3);//Saida
        printf("Maior: \"%d\"\n", numero_2);//Saida
    }

    //Probabilidade 6
    if((numero_1 < numero_2) && (numero_1 < numero_3) && (numero_2 < numero_3)){
        printf("Menor: \"%d\"\n", numero_1);//Saida
        printf("Intermediario: \"%d\"\n", numero_2);//Saida
        printf("Maior: \"%d\"\n", numero_3);//Saida
    }
    
    return 0;
}