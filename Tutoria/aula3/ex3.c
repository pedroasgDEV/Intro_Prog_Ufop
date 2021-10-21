/*
Exercício 3:
Faça um programa que leia um numero inteiro x, utiliza uma função para
avaliar se:
1º x é primo
2º x é par
3º x é ímpar
*/

//Bibliotecas 
#include <stdio.h>

//Prototio das funções
int typeVerif(int x); //Função de verificar tipo do numero

 //Funções
int typeVerif(int x){ //Função de verificar tipo do numero
    //Variaveis da função
    int p = 2;

    if(x <= 1){//Se ele for 0 ou 1
        if (x == 1){return 1;}//impar
        else {return 2;}//par
    }
    else{
        //Laço que ira verificar se o numero é primo
        while (p < x){
            if (x % p == 0){//Se ele for divisivel por um numero diferente dele mesmo e 1
                if (x % 2 != 0){ return 1;}//impar
                else { return 2;}//par
            }
            p++;
        }
        return 3; //Se for primo
    }
}

int main(){
    //Variaveis
    int x;

    //Entrada
    printf("Digite um numero: "); scanf("%d", &x); //Entrada do x

    while (x < 0){//se o numero não for natural
        printf("ERRO: Numero não é natural\n");
        printf("Digite um numero: "); scanf("%d", &x); //Entrada do x;
    }

    //Processamento
    switch (typeVerif(x)){
        case 1:
            printf("%d é impar\n", x);//Saida se for impar
            break;
        case 2:
            printf("%d é par\n", x);//Saida se for par
            break;
        default:
            printf("%d é primo\n", x);//Saida se for primo
            break;
    }

    return 0;
}