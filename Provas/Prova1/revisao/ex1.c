//Bibliotecas 
#include <stdio.h>

int main(){
    char c;
    printf("digite um caracter: ");scanf("%c", &c);
    if((c >= 65) && (c <= 90)){
        printf("%c é MAIUSCULO\n", c);
    }
    else if((c >= 97) && (c <= 122)){
        printf("%c é minusculo\n", c);
    }
    else{
        printf("%c é um simbolo\n", c);
    }
    return 0;
}