/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

/*
Questão 01
Codifique um programa para ler o número termos (quanto maior, melhor a precisão), calcular e
imprimar o valor de π.
*/

//Bibliotecas 
#include <stdio.h>
#include <math.h>

//Prototio das função que calcula o pi
double pi(int numb); 

//Funções 
double pi(int numb){ //Função que calcula o pi
    //Variaveis da função
    int i = 1;
    double s = 1;
    
    while (i < numb){
        if((i+1) % 2 == 0){//Verifica se o termo será positivo
            s -= 1.0/pow(1 + (2 * i) , 3);
        }
        else{//Verifica se o termo for negativo
            s += 1.0/pow(1 + (2 * i), 3);
        }
        i++;
    }

    return pow(s * 32.0, 1.0/3);
}

int main(){
    //Variaveis
    int numb;

    //Entrada
    printf("Quantos termos serao calculados para pi: "); scanf("%d", &numb); //Entrada da quantidade de termos

    //Erro
    while (numb <=0){ //Caso algum valor seja menor que 1
        printf("ERRO: O valor inserido deve ser maior que zero\n");
        printf("Quantos termos serao calculados para pi: "); scanf("%d", &numb); //Entrada da quantidade de termos
    }

    printf("Pi: %lf\n", pi(numb));
    return 0;
}