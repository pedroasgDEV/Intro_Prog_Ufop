/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

/*
Questão 01
Crie uma função que retorna o fatorial n! de um número n passado por parâmetro.
*/

//Bibliotecas
#include <stdio.h>

//Prototipo da função que ira fatorar n
long long fat(int n);

int main(){
    //Variaveis
    int n;


    //Função que ira fatorar n
    long long fat(int n){
        //Varieaveis da função
        long long temp = 1;
        int i = 1;

        //Laço que ira fazer a fatoração
        while (i <= n){
            temp *= i;
            i++;
        }

        return temp;
    }

    //Entrada
    printf("Digite o valor de n: "); scanf("%d", &n);

    //Saida
    printf("%d!: %lld\n", n, fat(n)); //Saida da fatoração
    
    return 0;
}