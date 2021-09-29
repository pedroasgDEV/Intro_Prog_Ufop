/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

/*
Questão 01
Crie um programa que, dada uma letra, escreve na tela se essa letra é ou não uma vogal
(considere letras maiúsculas e minúsculas).
*/

//Bibliotecas
#include <stdio.h>

//Variaveis Globais
char letra;

int main(){

    //Entrada
    printf("Digite somente uma letra: ");
    scanf("%c", &letra);

    //Processamento
    //Se for uma vogal
    if( (letra == 'a') || (letra == 'e') || (letra == 'i') || (letra == 'o') || (letra == 'u') ||
        (letra == 'A') || (letra == 'E') || (letra == 'I') || (letra == 'O') || (letra == 'U') ){

        printf("A letra \"%c\" que você digitou é uma vogal\n", letra);//Saida
    }

    //Se não for uma vogal
    else{
        printf("A letra \"%c\" que você digitou não é uma vogal\n", letra);//Saida
    }

    return 0;
}