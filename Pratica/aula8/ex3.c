/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

/*
Questão 03
Faça um programa que leia o nome completo de uma pessoa com até 70 caracteres.
*/

//Bibliotecas
#include <stdio.h>
#include <string.h>

//Tamanho maximo da string
#define n 70

int main(){
    //Variaveis
    int n_ltts = 0, lst_wrd = 0;
    //Strings
    char str[n], lst_wrd_str[n];
    
    //Entrada da string
    printf("Digite o nome completo: ");
    fgets(str, n, stdin); str[strlen(str) - 1] = '\0';

    //Numero de letras
    for(int i = 0; i < strlen(str) ; i++){
        if(str[i] == ' '){
            lst_wrd = 0;
            continue;
        }
        lst_wrd++;
        n_ltts++;
    }

    //Separando a ultima palvra em una string
    for(int i = strlen(str) - lst_wrd, j = 0; i < strlen(str); i++, j++){
            lst_wrd_str[j] = str[i];
    }
    lst_wrd_str[lst_wrd] = '\0';

    //Tira a ultima palvra da string principal
    str[strlen(str) - (lst_wrd + 1)] = '\0';

    //Saida
    printf("%s, %s\n", lst_wrd_str, str);
    printf("Total de letras: %d\n", n_ltts - 1);
    printf("Total de letras do último sobrenome: %d\n", lst_wrd - 1);

    return 0;
}