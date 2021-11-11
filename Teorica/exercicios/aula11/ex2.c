//Bibliotecas
#include <stdio.h>
#include <string.h>

int main(){
    char str[50];
    fgets(str, 50, stdin);
    if(strcmp(str, "UFOP\n") == 0){printf("Bem vindo a Ouro Preto!\n");}
    return 0;
}