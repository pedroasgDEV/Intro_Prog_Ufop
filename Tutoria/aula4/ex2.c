//Bibliotecas 
#include <stdio.h>

//Prototio das funções
void ordenado(int n); //Função de criar um prisma

 //Funções
void ordenado(int n){ //Função de criar um prisma
    //Variaveis da função
    if(n >= 0){
        for (int x = 0; x <= n; x++){
            for (int y = 0; y <= n; y++){
                printf("(%d, %d)\n", x, y);
            }
        }
    }

    else{
        for (int x = n; x <= 0; x++){
            for (int y = n; y <= 0; y++){
                printf("(%d, %d)\n", x, y);
            }
        }
    }
}

int main(){
    //Variaveis
    int n;

    //Entrada
    printf("Digite um numero: "); scanf("%d", &n); 

    //Processamento
    ordenado(n);
    return 0;
}