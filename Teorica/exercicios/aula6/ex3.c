//Bibliotecas 
#include <stdio.h>

int main(){
    //Variaveis :(
    double nota;

    //Funções
    //Função de verificação de conceito
    void conceito(double nota){
        char conceito;
        if ((nota <= 10.) && (nota >= 9.)){
            conceito = 'A';
        }
        else if ((nota < 9.) && (nota >= 8.)){
            conceito = 'B';
        }
        else if ((nota < 8.) && (nota >= 7.)){
            conceito = 'C';
        }
        else if ((nota < 7.) && (nota >= 6.)){
            conceito = 'D';
        }
        else if (nota < 6){
            conceito = 'F';
        }
        printf("O conceito do aluno é é %c\n", conceito);//Saida
    }

    //Entrada
    printf("digite a nota do aluno: "); scanf("%lf", &nota);
    
    //Processamento
    conceito(nota);

    return 0;
}
