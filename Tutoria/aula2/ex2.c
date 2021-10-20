/*
Questão 2:
Dados 2 números inteiros x e y, crie uma função do tipo void que
calcule a soma dos primos no intervalo ]x,y]. Imprima o resultado dentro do
main().
*/

//Bibliotecas 
#include <stdio.h>

//Prototio das funções
void calcIntervalo(int *x, int *y, int *numb); //Função da soma dos numeros primos no intervalo
int primo(int i); //Função para verificar se é primo

//Funções
int primo(int i){ //Função para verificar se é primo
    //Variaveis da função
    int p = 2;
    
    if(i <= 1){//Se ele for 0 ou 1
        return 0; //Se não for primo
    }
    else{
        //Laço que ira verificar se o numero é primo
        while ( p < i){
            if (i % p == 0){//Se ele for divisivel por um numero diferente dele mesmo e 1
                return 0; //se não for primo
            }
            p++;
        }
        return 1; //Se for primo
    }
}

void calcIntervalo(int *x, int *y, int *numb){ //Função da soma dos numeros primos no intervalo
    //Variaveis da função
    int i = *x + 1;

    ///Laço de repetição
    while(i <= *y){
        if (primo(i) == 1){ //Se o numero for primo
            *numb += i; //Soma dos primos
        }
        i++;
    }
}

int main(){
    //Variaveis
    int x, y; 
    int numb = 0;

    //Entrada
    printf("Digite um numero para x: "); scanf("%d", &x); //Entrada do x
    printf("Digite um numero para y: "); scanf("%d", &y); //Entrada do y

    //Erro
    while (x >= y){ //Caso o x não for menor que o z
        printf("ERRO: o x deve ser menor que o y\n");
        printf("Digite um numero para x: "); scanf("%d", &x); //Entrada do x
        printf("Digite um numero para y: "); scanf("%d", &y); //Entrada do y
    }

    while ((x < 0) || (y < 0)){//se os numeros não forem naturais
        printf("ERRO: Numeros não são naturais\n");
        printf("Digite um numero para x: "); scanf("%d", &x); //Entrada do x
        printf("Digite um numero para y: "); scanf("%d", &y); //Entrada do y

    }

    //Processamento
    calcIntervalo(&x, &y, &numb);
    
    //Saida
    printf("A soma dos primos entre %d e %d é %d\n", x, y, numb);

    return 0;
}