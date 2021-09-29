/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

/*
Questão 02
Crie um programa em C que lê um ano e calcula e imprime se o ano digitado é bissexto. Para saber
se um ano é bissexto devemos utilizar as seguintes regras:
• O ano tem que ser divisı́vel por 4, mas não pode ser divisı́vel por 100;
• Porém, se for divisı́vel por 100, tem que ser divisı́vel também por 400.
*/

//Bibliotecas
#include <stdio.h>

//Variaveis Globais
int ano;

int main(){

    //Entrada
    printf("Digite um ano: ");
    scanf("%d", &ano);

    //Processamento
    //Se o ano for bissexto
    if( ((ano % 4 == 0) && ( ano % 100 != 0 )) || ((ano % 4 == 0) && (ano % 100 == 0) && (ano % 400 == 0)) ){

        printf("O ano \"%d\" é bissexto\n", ano);//Saida
    }

    //Se não for bissexto
    else{
        printf("O ano \"%d\" não é bissexto\n", ano);//Saida
    }

    return 0;
}