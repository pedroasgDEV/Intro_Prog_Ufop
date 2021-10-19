
/*
Questao 1:
O programa deve ler 3 números inteiros (x, y, z) e criar uma função do
tipo void que recebe os 3 valores por parâmetros e calcula no intervalo [x,z]
quanto são os múltiplos de y. A impressão deve ser feita no main().
*/

//Bibliotecas 
#include <stdio.h>

//Prototio das funções
void calcIntervalo(int *x, int *y, int *z, int *numb);

int main(){
    //Variaveis
    int x, y , z;
    int numb = 0; //numero de multiplos de y

    //Funções
    void calcIntervalo(int *x, int *y, int *z, int *numb){ 
        //Variaveis da função
        int i = *x;

        ///Laço de repetição
        while(i <= *z){
            if (i % *y == 0){ //Se o numero for multiplo de y
                (*numb)++;
            }
            i++;
        }
    }

    //Entrada
    printf("Digite um numero para x: "); scanf("%d", &x); //Entrada do x
    printf("Digite um numero para y: "); scanf("%d", &y); //Entrada do y
    printf("Digite um numero para z: "); scanf("%d", &z); //Entrada do z

    //Erro
    while (x >= z){ //Caso o x não for menor que o z
        printf("ERRO: o x deve ser menor que o z\n");
        printf("Digite um numero para x: "); scanf("%d", &x); //Entrada do x
        printf("Digite um numero para y: "); scanf("%d", &y); //Entrada do y
        printf("Digite um numero para z: "); scanf("%d", &z); //Entrada do z
    }

    //Processamento
    calcIntervalo(&x, &y, &z, &numb);
    
    //Saida
    printf("Existem %d multiplos de %d no intervalo de %d ate %d\n", numb, y, x, z);

    return 0;
}