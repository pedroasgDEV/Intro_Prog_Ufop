/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

/*
Questão 02
Faça um programa que leia diversas palavras e informe se elas são palı́ndromos. O programa deve
terminar quando for digitada para palavra “FIM”.
*/

//Bibliotecas
#include <stdio.h>
#include <string.h>

//Tamanho array
#define n 100

int main(){
    //Strings
    char str[n];

    while (1){
       //Entrada
        printf("Digite uma palavra ou FIM para sair: ");
        fgets(str, n, stdin); str[strlen(str) - 1] = '\0';

        //Saida do while
        if(strcmp(str, "FIM") == 0){break;}

        //Verifica se é polidromo
        for(int i = 0; i < strlen(str) ; i++){
            if(str[i] != str[strlen(str) - (i + 1)]){
                printf("Não é um polidromo\n");
                break;
            }
            else if(i == strlen(str) - 1){printf("É um polidromo\n");}
        }
    }

    return 0;
}