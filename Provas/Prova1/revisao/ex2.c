#include <stdio.h>
#include <math.h>

int soma(int x, int y);
int produto(int x, int y);
int quadrado(int x);
int raiz(int x, int y);
float seno(int x, int y);
int modulo(int x);

int soma(int x, int y){
    return x + y;
}
int produto(int x, int y){
    return x * pow(y, 2);
}
int quadrado(int x){
    return pow(x, 2);
}
int raiz(int x, int y){
    return sqrt(pow(x, 2) + pow(y, 2));
}
float seno(int x, int y){
    return sin(x - y);
}
int modulo(int x){
    return sqrt(pow(x, 2));
}

int main(){
    int x, y;
    printf("Digite dois numeros: ");scanf("%d %d", &x, &y);
    printf("%d\n%d\n%d\n%d\n%f\n%d\n", soma(x, y), produto(x, y), quadrado(x), raiz(x, y), seno(x, y), modulo(x));
    return 0;
}