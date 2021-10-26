#include <stdio.h>

void som(int *x);

void som(int *x){
    if(*x % 2 == 0){*x += 5;}
    else{*x += 8;}
}
int main(){
    int x;
    printf("Digite um numero: "); scanf("%d", &x);
    som(&x);
    printf("%d\n", x);
    return 0;
}