#include <stdio.h>

double I(int x);
double F(int x);

double I(int x){
    if(x <= 5){
        return x*5.45;
    }
    else if((x > 5) && (x <= 15)){
        return 22.5 + (x - 5) * 4;
    }
    else{
        return 52.5 + (x - 15) * 2.95;
    }
}
double F(int x){
    if(x <= 5){
        return x*4;
    }
    else if((x > 5) && (x <= 15)){
        return 17.75 + (x - 5) * 2.95;
    }
    else{
        return x * 1.5;
    }
}
int main(){
    int x;
    char c;
    double total;
    printf("Qual seu plano(I ou F): ");
    scanf("%c", &c);
    printf("Quantos jogos alugou: ");
    scanf("%d", &x);
    if (c == 'I'){
        total = I(x) + 9.9;
    }
    if (c == 'F'){
        total = F(x) + 19.9;
    }
    printf("O total a ser pago é %lf\n", total);
    printf("O preco medio por jogo é %lf\n", total/x);
    return 0;
}