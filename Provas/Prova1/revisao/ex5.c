#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    srand(time(NULL));

    int x, y;
    
    printf("Chute a soma soma dos dados (2 a 12)"); scanf("%d", &x);
    y = 2 + rand() % 12;
    if(x == y){printf("O resultado é %d, ACERTOU\n", y);}
    else{printf("O resultado é %d, ERROU\n", y);}
    return 0;
}