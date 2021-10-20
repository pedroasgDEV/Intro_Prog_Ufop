/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

/*
Questão 02
Um número natural é primo se ele possui apenas dois divisores distintos. Assim, um número n maior
que 1 (n > 1) é primo se n for divisı́vel apenas por si próprio n e por 1.
*/

//Bibliotecas
#include <stdio.h>

//Prototipo da função que ira verificar se o numero é primo
int is_prime(int n);

int is_prime(int n){ //Função para verificar se é primo
    //Variaveis da função
    int p = 2;

    if(n <= 1){//Se ele for 0 ou 1
        return 0; //Se não for primo
    }
    else{
        //Laço que ira verificar se o numero é primo
        while (p < n){
            if (n % p == 0){//Se ele for divisivel por um numero diferente dele mesmo e 1
                return 0; //Se não for primo
            }
            p++;
        }
        return 1; //Se for primo
    }
}

int main(){
    //Variaveis
    int n;

    //Entrada
    printf("Digite um número: "); scanf("%d", &n);

    //Erro
    while (n < 0){//se o numero não for natural
        printf("ERRO: Numero não é natural\n");
        printf("Digite um número: "); scanf("%d", &n);
    }
    

    //Processamento para saida
    switch (is_prime(n)){
        case 1:
            printf("%d é um número primo!\n", n); //Saida
            break;

        default:
            printf("%d NAO é um número primo!\n", n); //Saida
            break;
    }

    return 0;
}