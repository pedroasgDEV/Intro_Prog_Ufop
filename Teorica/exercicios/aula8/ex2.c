//Bibliotecas 
#include <stdio.h>

//Prototio das funções
int MDC(int nmr_1, int nmr_2);//Prototipo da função de MDC
void troca(int *nmr_1, int *nmr_2);//Prototio da função de troca

int main(){
    //Funções

    void troca(int *nmr_1, int *nmr_2){ //Função de troca
        //Variaveis da função
        int temp = *nmr_1;
        *nmr_1 = *nmr_2;
        *nmr_2 = temp;
    }

    int MDC(int nmr_1, int nmr_2){ //Função de MDC
        //Variaveis da função
        int divisor;

        if(nmr_1 < nmr_2){ // se o numero 2 é maior que numero 1
            troca(&nmr_1, &nmr_2);//Troca os numeros
        }

        do{//Loop dp MDC
            divisor = nmr_1 % nmr_2;
            nmr_1 = nmr_2;
            nmr_2 = divisor;
        } while (divisor != 0);
        
        
        return nmr_1;//Retorno o MDC
    }

    //Variaveis
    int nmr_1, nmr_2;

    //Entrada
    printf("Digite um numero positivo diferente de 0: "); scanf("%d", &nmr_1); //Entrada do primeiro numeros do MDC
    printf("Digite outro numero positivo diferente de 0: "); scanf("%d", &nmr_2); //Entrada do segundo numeros do MDC
    
    //Erro
    while ((nmr_1 <= 0) || (nmr_2 <= 0)){
        printf("ERRO: numeros invalidos\n");
        printf("Digite um numero positivo diferente de 0: "); scanf("%d", &nmr_1); //Entrada do primeiro numeros do MDC
        printf("Digite outro numero positivo diferente de 0: "); scanf("%d", &nmr_2); //Entrada do segundo numeros do MDC
    }
    
    //Saida
    printf("O MDC dos numeros é %d\n", MDC(nmr_1, nmr_2));// Saida do MDC

    return 0;
}