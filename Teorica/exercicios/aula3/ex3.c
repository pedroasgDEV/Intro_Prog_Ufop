//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Variaveis globais
int n1, n2; 

int main(){
    //gerando numero aleatorio 
    srand(time(NULL));

    //Entrada
    scanf("%d", &n1);
    scanf("%d", &n2);
    
    //Processamento
    int na = n1 + rand() % (n2 - n1 + 1);

    printf(" o numero aleatorio é %d\n ", na);//Saida
    return 0;
};