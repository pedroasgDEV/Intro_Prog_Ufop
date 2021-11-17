/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

/*
Questão 04
O censurador: crie um programa que lê uma frase e substitui as ocorrências do caractere ‘a’ por ‘@’,
‘e’ por ‘ ’, ‘i’ por ‘|’, ‘o’ por ‘0’, ‘u’ por ‘#’, e ‘s’ por ‘$’.
*/

//Bibliotecas
#include <stdio.h>
#include <string.h>

//Tamanho maximo da string
#define n 100

int main(){
    //Strings
    char str[n];
    
    //Entrada da string
    printf("Digite o texto para censurar: \n");
    fgets(str, n, stdin); str[strlen(str) - 1] = '\0';

    //Censura
    for(int i = 0; i < strlen(str) ; i++){
        switch (str[i]){
            case 'a': str[i] = '@'; break;
            case 'e': str[i] = '_'; break;
            case 'i': str[i] = '|'; break;
            case 'o': str[i] = '0'; break;
            case 'u': str[i] = '#'; break;
            case 's': str[i] = '$'; break;
            default: break;
        }
    }

    //Imprime a string
    printf("\n");
    printf("%s\n", str);

    return 0;
}