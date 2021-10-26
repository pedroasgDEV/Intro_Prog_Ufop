#include <stdio.h>

int main(){
    int x;
    printf("Digite sua idade: "); scanf("%d", &x);
    if(((x < 18) && (x >= 16)) || (x > 65)){printf("Seu voto é optativo");}
    else if(x < 16){printf("Voce nao pode votar");}
    else{printf("Voce deve votar");}
    printf("\n");
    return 0;
}