//Bibliotecas 
#include <stdio.h>

//Funções
void conversao(double *m, double *j, double *pe, double *po);

int main(){
    //Variaveis
    double metro;
    double jardas = 1.094;
    double pes = 3.281;
    double polegadas = 39.3701;

    //Funções
    //Função de conversao
    void conversao(double *m, double *j, double *pe, double *po){
        printf("Jardas = %.2lf\n", *m * *j);//saida do valor em jardas
        printf("Pés = %.2lf\n", *m * *pe);//saida do valor em pes
        printf("Polegadas = %.2lf\n", *m * *po);//saida do valor em polegadas
    }

    //Entrada
    printf("digite um valor em metros: "); scanf("%lf", &metro);
    
    //Processamento
    conversao(&metro, &jardas, &pes, &polegadas);

    return 0;
}