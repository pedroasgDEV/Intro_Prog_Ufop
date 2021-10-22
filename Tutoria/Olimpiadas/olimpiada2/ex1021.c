//Bibliotecas
#include <stdio.h>

//Prototipo da função
int div(int x, int y); //qnts vezes o numero x pode ser dividido por y

//Função
int div(int x, int y){
    int temp = 0; //qnts vezes o numero x pode ser dividido por y
    while (x - y >= 0){
        x -= y;
        temp++;
    }
    return temp;
}
 
int main() {
    
    //Variaveis
    double dinheiro;
    int notas, moedas;

    //Entrada
    printf("digite um valor: "); scanf("%.2lf", &dinheiro);

    notas = (int) dinheiro;
    moedas = (int) ((dinheiro - (double) notas)*100);

    //Saida
    //nota de 100
    printf("%d nota(s) de R$ 100.00\n", div(notas, 100));
    notas -= 100*div(notas, 100);

    //nota de 50
    printf("%d nota(s) de R$ 50.00\n", div(notas, 50));
    notas -= 50*div(notas, 50);

    //nota de 20
    printf("%d nota(s) de R$ 20.00\n",div(notas, 20));
    notas -= 20*div(notas, 20);

    //nota de 10
    printf("%d nota(s) de R$ 10.00\n", div(notas, 10));
    notas -= 10*div(notas, 10);

    //nota de 5
    printf("%d nota(s) de R$ 5.00\n", div(notas, 5));
    notas -= 5*div(notas, 5);

    //nota de 2
    printf("%d nota(s) de R$ 2.00\n", div(notas, 2));
    notas -= 2*div(notas, 2);

    printf("MOEDAS:\n");

    //moeda de 1
    printf("%d moeda(s) de R$ 1.00\n", div(notas, 1));
    notas -= 1*div(notas, 1);
    
    //moeda de 0.50
    printf("%d moeda(s) de R$ 0.50\n", div(moedas, 50));
    moedas -= 50*div(moedas, 50);

    //moeda de 25
    printf("%d moeda(s) de R$ 0.25\n",div(moedas, 25));
    moedas -= 25*div(moedas, 25);

    //moeda de 0.10
    printf("%d moeda(s) de R$ 0.10\n", div(moedas, 10));
    moedas -= 10*div(moedas, 10);

    //moeda de 0.05
    printf("%d moeda(s) de R$ 0.05\n", div(moedas, 5));
    moedas -= 5*div(moedas, 5);

    //moeda de 0.01
    printf("%d moeda(s) de R$ 0.01\n", div(moedas, 1));

    return 0;
}
