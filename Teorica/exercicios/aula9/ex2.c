//Bibliotecas
#include <stdio.h>

int main(){
    int p, a = 0;
    for(int i = 0; i <= 50; i++){
        printf("Idade: "); scanf("%d", &p);
        if(p > 20){a++;}
    }
    printf("%d possuem mais de 20 anos\n", a);
    return 0;
}