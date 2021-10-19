/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

/*
Questão 01
Faça uma única função que converte um valor em graus Celsius para Fahrenheit e Kelvin. Crie também
uma função main() para ler o valor em Celsius digitado pelo usuário e imprimir este valor convertido
em Fahrenheit e Kelvin.
*/

//Bibliotecas
#include <stdio.h>

//Prototipo da função que ira converter uma temperatura em celsius para fahrenheit e kelvin
void converterCelsius(float celsius, float *fahrenheit, float *kelvin);

int main(){
    //Variaveis
    float celsius, fahrenheit, kelvin;


    //Função que ira converter uma temperatura em celsius para fahrenheit e kelvin
    void converterCelsius(float celsius, float *fahrenheit, float *kelvin){
        *fahrenheit = (celsius * 9/5) + 32.00; // Celsius para Fahrenheit
        *kelvin = celsius + 273.15; //Celsius para Kelvin
    }

    //Entrada
    printf("Digite uma temperatura em celsius: "); scanf("%f", &celsius);

    //Processamento
    converterCelsius(celsius, &fahrenheit, &kelvin);

    //Saida
    printf("Em fahrenheit é: %.2f\n", fahrenheit); //Saida em Fahrenheit
    printf("Em kelvin é: %.2f\n", kelvin); //Saida em Kelvin
    return 0;
}