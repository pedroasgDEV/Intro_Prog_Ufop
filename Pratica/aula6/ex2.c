/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

/*
Questão 02
Faça um programa que leia um CPF (somente números) e verifique se ele é válido. O cálculo deve
ser feito em uma função, que recebe o CPF e retorna 1, se for válido e 0, caso contrário.
*/

//Bibliotecas 
#include <stdio.h>
#include <math.h>

//Prototio da função que valida o cpf com o primeiro digito
int valida_1(long cpf);

//Prototio da função que valida o cpf com o segundo digito
int valida_2(long cpf);

//Prototipo da função que separa um digito especifico
int digito_cpf(long cpf, int i);

//Função que separa um digito especifico
int digito_cpf(long cpf, int i){
    //Variaveis da função
    int x = 11;
    int alg;
    long temp = cpf;
    
    //Laço que separa o digito
    while (x >= i){
        alg = 0;
        
        while (temp - (long) pow(10, x - 1) >= 0){
            temp -= (long) pow(10, x - 1);
            alg++;
        }

        cpf -= alg * (long) pow(10, x - 1);
        temp = cpf;
        x--;
    }

    return alg;
}

//Função que valida o cpf com o primeiro digito
int valida_2(long cpf){ 
    //Variaveis da função
    int i = 0;
    int soma = 0;
    
    //Laço que faz o calculo da validação
    while (i < 10){
        soma += digito_cpf(cpf, 11 - i) * (11 - i); 
        i++;
    }

    //Faz a validação
    if((soma * 10) % 11 == digito_cpf(cpf, 1)){ //Valido
        return 1;
    }
    else{ //Invalido
        return 0;
    }

}

//Função que valida o cpf com o segundo digito
int valida_1(long cpf){
    //Variaveis da função
    int i = 0;
    int soma = 0;
    
    //Laço que faz o calculo da validação
    while (i < 9){
        soma += digito_cpf(cpf, 11 - i) * (11 - (i + 1)); 
        i++;
    }

    //Faz a validação
    if((soma * 10) % 11 == digito_cpf(cpf, 2)){ //Valido
        return valida_2(cpf); //Chama a função que valida com segundo digito
    }
    else{ //Invalido
        return 0;
    }

}

int main(){
    //Variaveis
    long cpf;

    //Entrada
    printf("Digite seu cpf: "); scanf("%ld", &cpf); //Entrada do cpf

    //Erro
    while (cpf - (long) pow(10, 11) >= 0){
        printf("ERRO: O cpf digitado possui mais de 11 digitos\n");
        printf("Digite seu cpf: "); scanf("%ld", &cpf); //Entrada do cpf
    }
    
    switch(valida_1(cpf)){
        case 1:
            printf("1: CPF valido\n");
            break;

        default:
            printf("0: CPF invalido\n");
    }

    return 0;
}