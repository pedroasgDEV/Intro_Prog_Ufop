#include <stdio.h>

int main(){
    int x1, x2, x3, x4, x5, menor;
    printf("Digite 5 numeros: ");scanf("%d", &x1); menor = x1;
    scanf("%d", &x2); if(x2 < menor){menor = x2;}
    scanf("%d", &x3); if(x3 < menor){menor = x3;}
    scanf("%d", &x4); if(x4 < menor){menor = x4;}
    scanf("%d", &x5); if(x5 < menor){menor = x5;}
    printf("O menor numero é %d\n", menor);
    return 0;
}