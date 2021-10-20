/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

/*
Questão 01
Crie um programa para converter valores em diferentes unidades de ângulo e temperatura.
*/

#define pi 3.14159265358979323846 //valor de pi

//Bibliotecas
#include <stdio.h>

//Prototipo de funções
//Funções de temperatura
double celsius_fahrenheit(double celsius); //De Celsius para Fahrenheit
double celsius_kelvin(double celsius); //De Celsius para Kelvin
double fahrenheit_celsius(double fahrenheit); //De Fahrenheit para Celsius
double fahrenheit_kelvin(double fahrenheit); //De Fahrenheit para Kelvin
double kelvin_celsius(double kelvin); //De Kelvin para Celsius
double kelvin_fahrenheit(double kelvin); //De Kelvin para Fahrenheit

//Funções de angulo
double grau_radiano(double graus); //De Graus para Radianos
double radiano_grau(double radianos); //De Radianos para Graus

//Funções das telas
void inicio(); //tela inicial
void angulo(); //tela de conversão de angulo
void temperatura(); //tela de conversão de temperatura

//Funções

//Funções de temperatura
    //Função de conversão Celsius para Fahrenheit
double celsius_fahrenheit(double celsius){
    return (celsius * 9/5) + 32;//Processamento
}

    //Função de conversão Celsius para Kelvin
double celsius_kelvin(double celsius){
    return celsius + 273.15;//Processamento
}

    //Função de conversão Fahrenheit para Celsius
double fahrenheit_celsius(double fahrenheit){
    return (fahrenheit - 32) * 5/9;//Processamento
}

    //Função de conversão Fahrenheit para Kelvin
double fahrenheit_kelvin(double fahrenheit){
    return ((fahrenheit - 32) * 5/9) + 273.15;//Processamento
}

    //Função de conversão Kelvin para Celsius
double kelvin_celsius(double kelvin){
    return kelvin - 273.15;//Processamento
}

    //Função de conversão Kelvin para Fahrenheit
double kelvin_fahrenheit(double kelvin){
    return ((kelvin - 273.15) * 9/5) + 32;//Processamento
}

//Funções de angulo
    //Função de conversão Graus para Radianos
double grau_radiano(double graus){
    return (pi * graus)/180.00;//Processamento
}

    //Função de conversão Radianos para Graus
double radiano_grau(double radianos){
    return (180.00 * radianos)/pi;//Processamento   
}

//Funções das telas
    //Função de tela de conversão de angulo
void angulo(){
    //Variaveis da função
    double graus;
    double radianos;
    int opcao;


    printf("\nQual a unidade de origem?\n\n1) Graus\n2) Radianos\n\nSelecione uma opcao:");
    scanf("%d",&opcao);//Entrada da tela de conversão de angulo

    //Define qual conversão será feita
    switch (opcao){
        case 1:
            printf("\nDigite o valor em Graus:");scanf("%lf", &graus);//Entrada do angulo em Graus
            printf("Valor em Radianos: %lf\n", grau_radiano(graus));//Saida do angulo em Radianos
            break;
        case 2:
            printf("\nDigite o valor em Radianos:");scanf("%lf",&radianos);//Entrada do angulo em Radianos
            printf("Valor em Graus: %lf\n", radiano_grau(radianos));//Saida do angulo em Graus
            break;
        default:
            printf("\nERRO: Digite uma opção valida\n\n");//Mensagem de erro
            angulo();
            break;
    }
}

    //Função de tela de conversão de temperatura
void temperatura(){
    //Variaveis da função
    int opcao;
    double celsius;
    double fahrenheit;
    double kelvin;

    printf("\nQual a unidade de origem?\n\n1) Celsius\n2) Fahrenheit\n3) Kelvin\n\nSelecione uma opcao:");
    scanf("%d",&opcao);//Entrada da tela de conversão de temperatura

    //Define qual conversão será feita
    switch (opcao){
        case 1:
            printf("\nDigite o valor em Celsius:");scanf("%lf", &celsius);//Entrada da temperatura em Celsius
            printf("Valor em Fahrenheit: %.2lf\n", celsius_fahrenheit(celsius));//Saida da temperatura em Fahrenheit
            printf("Valor em Kelvin: %.2lf\n", celsius_kelvin(celsius));//Saida da temperatura em Kelvin
            break;
        case 2:
            printf("\nDigite o valor em Fahrenheit:");scanf("%lf", &fahrenheit);//Entrada da temperatura em Fahrenheit
            printf("Valor em Celsius: %.2lf\n", fahrenheit_celsius(fahrenheit));//Saida da temperatura em Celsius
            printf("Valor em Kelvin: %.2lf\n", fahrenheit_kelvin(fahrenheit));//Saida da temperatura em Kelvin
            break;
        case 3:
            printf("\nDigite o valor em Kelvin:");scanf("%lf", &kelvin);//Entrada da temperatura em Kelvin
            printf("Valor em Celsius: %.2lf\n", kelvin_celsius(kelvin));//Saida da temperatura em Celsius
            printf("Valor em Fahrenheit: %.2lf\n", kelvin_fahrenheit(kelvin));//Saida da temperatura em Fahrenheit
            break;
        default:
            printf("\nERRO: Digite uma opção valida\n\n");//Mensagem de erro
            temperatura();
            break;
    }
}

    //Função de tela inicial
void inicio(){
    //Variaveis da função
    int opcao;
    printf("### CONVERSOR DE UNIDADES ###\n\n1) Angulo\n2) Temperatura\n\nDigite uma opcao:");
    scanf("%d",&opcao);//Entrada da tela inicial

    //Define próxima tela 
    switch (opcao){
        case 1:
            angulo();//Ir para tela de conversão de angulo
            break;
        case 2:
            temperatura();//Ir para tela de conversão de temperatura
            break;
        default:
            printf("\nERRO: Digite uma opção valida\n\n");//Mensagem de erro
            inicio();
            break;
    }
} 



int main(){
    inicio();// Iniciar programa

    return 0;
}