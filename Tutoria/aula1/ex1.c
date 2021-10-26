/*
Questão 01:
O programa deve ler um valor inteiro X indefinidas vezes. (O programa irá parar
quando o valor de X for igual a 0). Para cada X lido, imprima a soma dos 5 pares
consecutivos a partir de X, inclusive o X, se for par. Se o valor de entrada for 4, por
exemplo, a saída deve ser 40, que é o resultado da operação: 4+6+8+10+12, enquanto
que se o valor de entrada for 11, por exemplo, a saída deve ser 80, que é a soma de
12+14+16+18+20.
*/

//Bibliotecas
#include <stdio.h>

int main(){
    //Variaveis
    int x;
    int i = 0;
    int som = 0;

    while (1){
        //Entrada
        printf("Digite um numero: ");
        scanf("%d", &x);
        if(x == 0){break;}
        while (i < 5){
            if(x % 2 == 0){
                som += x;
                i++;
            }
            x++;
        }
        i = 0;
        printf("%d\n", som);
        som = 0;
    }
    return 0;
}