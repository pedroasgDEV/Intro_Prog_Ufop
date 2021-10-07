//Bibliotecas 
#include <stdio.h>

//Funções
void duplica(int *n);

int main(){
    //Variaveis
    int numb;

    //Funções
    //Função que duplica valor de variavel
    void duplica(int *n){
        printf("o dobro do valor %d é %d\n", *n, *n * 2);//Saida do valor duplicado
    }

    //Entrada
    printf("digite um valor inteiro: "); scanf("%d", &numb);
    
    //Processamento
    duplica(&numb);

    return 0;
}