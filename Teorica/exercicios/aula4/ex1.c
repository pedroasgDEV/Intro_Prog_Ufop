//Bibliotecas 
#include <stdio.h>

//Variaveis globais
int a, b;

int main(){
    //Entrada
    scanf("%d %d", &a, &b);

    //Processamento
    if( a > b){
        printf("%i é o maior\n", a);//Saida
    }
    else{
        printf("%i é o maior\n", b);//Saida
    }
    return 0;
}
