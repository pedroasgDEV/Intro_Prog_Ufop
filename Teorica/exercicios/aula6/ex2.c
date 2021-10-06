//Bibliotecas 
#include <stdio.h>

/* 
Esperava variaveis globais aqui né?
Bom, eu tbm, mas o preofessor disse que não é uma boa pratica,
eu acredito que depende, codigos pequenos como esse, com poucas variaveis,
elas não geram confusão para vc que esta lendo, mas os grandes com muitas variaveis sim,
então é melhor começar desde o começo,
sou louco por estar conversando com meu codigo?
sim, mas eu fiz ele, "i have the power hahaha(risadas malignas insanas)"
*/

//Aqui tbm não vão ter funcões globais

int main(){
    //Variaveis :(
    int a,b,c;

    //Funções
    //Função que calcula o perimetro de um triangulo
    void perimetro(int a, int b, int c){
        printf("O perimetro do triangulo é %d\n", a + b + c);//Saida
    }

    //Entrada
    printf("digite os lados de um triangulo: "); scanf("%d", &a);scanf("%d", &b);scanf("%d", &c);
    
    //Processamento
    perimetro(a,b,c);

    return 0;
}
