
/*
Exercício 1:
O usuário irá digitar x números, positivos ou negativos, chega ao fim ao ser
enviado o numero zero.
*/

//Bibliotecas 
#include <stdio.h>

int main(){
    //Variaveis
    int numb, maior, menor;
    double media = 0.0;
    int i = 0;//contador

    printf("Digite um numero: ");scanf("%d", &numb);//entrada

    maior = numb;
    menor = numb;

    while (numb != 0){
        media += numb; //soma para media
        i++;
        printf("Digite um numero: ");scanf("%d", &numb);//entrada
        if(numb > maior){ maior = numb;} //Se o numero digitado é o maior
        if(numb < menor){ menor = numb;} //Se o numero digitado é o menor
    }

    printf("O maior: %d\n", maior); //saida do maior
    printf("O menor: %d\n", menor); //saida do menor
    if(media != 0)
        printf("A media: %.2lf\n", media/ (double) i); //saida do maior
    return 0;
}