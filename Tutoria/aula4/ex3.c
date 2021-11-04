//Bibliotecas 
#include <stdio.h>

int main(){
    //Variaveis
    char c; int p = 0;

    for(int i = 0; i < 6; i++){
        printf("Venceu( V ) ou perdeu( P )"); scanf("%c", &c);
        if((c == 'V') || (c == 'v')){p++;}
        getchar();
    }

    switch (p){
        case 6: case 5:
            printf("1\n"); break;
        case 4: case 3:
            printf("2\n"); break;
        case 2: case 1:
            printf("3\n"); break;
        default:
            printf("-1\n");
    }
}