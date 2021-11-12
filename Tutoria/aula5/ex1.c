//Bibliotecas
#include <stdio.h>
#include <string.h>

//Tamanho array
#define n 100

int main(){
    //Strings
    char str[n];

    //Entrada
    printf("Digite uma palavra: ");
    fgets(str, n, stdin); str[strlen(str) - 1] = '\0';

    //Adico
    for(int i = 0; i < strlen(str) ; i++){
        if(str[i] != str[strlen(str) - (i + 1)]){
            printf("Não é um polidromo\n");
            return 0;
        }
    }

    printf("É um polidromo\n");
    return 0;
}