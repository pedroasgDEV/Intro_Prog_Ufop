//Bibliotecas
#include <stdio.h>

int main(){
    printf("    "); for(int i = 1; i <= 20; i+=2){printf("%4d", i);} printf("\n");
    for(int i = 1; i <= 88; i+=2){printf("-");} printf("\n");
    for(int i = 1; i <= 20; i+=2){
        printf("%2d |", i);
        for(int p = 1; p <= 20; p+=2){
            printf("%4d", i * p);
        }
        printf("\n");
    }

    return 0;
}