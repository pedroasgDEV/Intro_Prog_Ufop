//Biblioteca
#include <stdio.h>

void troca3(int *a, int *b, int *c);

void troca3(int *a, int *b, int *c){
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}
int main(){
    int a, b, c;
    printf("Digite tres numeros: "); scanf("%d %d %d", &a, &b, &c);
    troca3(&a, &b, &c);
    printf("%d %d %d\n", a, b, c);
    return 0;
}