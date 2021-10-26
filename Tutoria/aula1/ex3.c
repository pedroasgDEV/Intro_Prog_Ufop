//Bibliotecas
#include <stdio.h>

//Prototipo da função
void fibonacci(int n);

//função
void fibonacci(int n){
    //Variaveis da função
    int i = 0;
    int v1 = 0;
    int v2 = 1;
    int temp;
    while (i < n){
        temp = v1;
        v1 = v2;
        printf(" %d", v1);
        v2 = v1 + temp;
        i++;
    }
    printf("\n");
}
int main(){
    //variaveis
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    fibonacci(n);
    return 0;
}
