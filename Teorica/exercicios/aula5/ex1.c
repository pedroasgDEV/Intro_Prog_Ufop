//Bibliotecas 
#include <stdio.h>

//Variaveis globais
double val_1, val_2;
char oper;

int main(){
    //Entrada
    printf("digite o operador (+,-,*,/): "); scanf("%c", &oper);
    printf("digite o primeiro valor: "); scanf("%lf", &val_1);
    printf("digite o segundo valor: "); scanf("%lf", &val_2);
    
    //Processamento
    //Se for soma
    if( oper == '+'){
        printf("O resultado de %.2lf %c %.2lf = %.2lf\n", val_1, oper, val_2, val_1 + val_2);//Saida
    }

    //Se for subtração
    else if(oper == '-'){
        printf("O resultado de %.2lf %c %.2lf = %.2lf\n", val_1, oper, val_2, val_1 - val_2);//Saida
    }

    //Se for multiplicação
    else if(oper == '*'){
        printf("O resultado de %.2lf %c %.2lf = %.2lf\n", val_1, oper, val_2, val_1 * val_2);//Saida
    }

    //Se for divisão
    else if(oper == '/'){
        printf("O resultado de %.2lf %c %.2lf = %.2lf\n", val_1, oper, val_2, val_1 / val_2);//Saida
    }
    else{
        printf("ERRO: operador não reconhecido\n");
    }
    return 0;
}
