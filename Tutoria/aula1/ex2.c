/*
Questão 02:
Ler um valor N. Calcular e escrever seu respectivo fatorial. Fatorial de N = N * (N-1)
* (N-2) * (N-3) * ... * 1.
*/

#include <stdio.h>

int main(){
    int x;
    int fat = 1;
    printf("Digite um numero: ");
    scanf("%d", &x);
    while (x > 0){
        fat *= x;
        x--;
    }
    printf("A fatorial é %d\n", fat);
    return 0;
}