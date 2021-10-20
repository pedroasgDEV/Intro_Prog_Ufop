/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

/*
Questão 03
Faça um programa que desenha um trapézio isósceles de bases x e y usando asteriscos. O usuário deve
informar os valores de x e y, que devem ser pares e tais que x < y.
*/

//Bibliotecas 
#include <stdio.h>

//Prototio das função que cria um Trapesio
void calcTrapesio(int x, int y); 

int main(){
    //Variaveis
    int x, y;

    //Funções
    void calcTrapesio(int x, int y){ //Função que cria um Trapesio
        //Variaveis da função
        int i = x;
        int p = 0;
        int c = 0;
        int espacos = (y - x) / 2; //espaços para dar forma ao Trapesio
        
        //Saida
        //Laço de repetição para fazer o Trapesio
        while(i <= y){ 
            if (i % 2 == 0){//verifica se o numero de i é par
                while(c < espacos){//faz os espaços que daram forma ao Trapesio
                    printf(" ");
                    c++;
                }
                c = 0;
                espacos--;

                while(p < i){//faz os * do Trapesio
                    printf("*");
                    p++;
                }
                p = 0;

                printf("\n");  
            }
            i++;
        }
    }
    //Entrada
    printf("Digite os valores de x e y: "); scanf("%d %d", &x, &y); //Entrada do x e y

    //Erro
    while ((x <= 0) || (y <= 0)){ //Caso algum dos valores for menor ou igual 0
        printf("ERRO: Apenas números maiores que 0 são aceitos.\n");
        printf("Digite os valores de x e y: "); scanf("%d %d", &x, &y); //Entrada do x e y
    }
    
    while ((x % 2 != 0) || (y % 2 != 0)){ //Caso algum dos valores for impar
        printf("ERRO: Apenas números pares são aceitos.\n");
        printf("Digite os valores de x e y: "); scanf("%d %d", &x, &y); //Entrada do x e y
    }

    while (x > y){ //Caso x for maior que y
        printf("ERRO: x deve ser menor que y.\n");
        printf("Digite os valores de x e y: "); scanf("%d %d", &x, &y); //Entrada do x e y
    }



    //Processamento
    calcTrapesio(x, y);

    return 0;
}