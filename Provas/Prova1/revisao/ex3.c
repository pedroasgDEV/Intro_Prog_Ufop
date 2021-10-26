#include <stdio.h>

void ord3(int a, int b, int c);

void ord3(int a, int b, int c){
    if((a < b) && (a < c)){
        printf("%d", a);
        if (b < c){
            printf(" %d %d", b, c);
        }
        else{
            printf(" %d %d", c, b);
        }
    }
    else if((b < a) && (b < c)){
        printf("%d", b);
        if (a < c){
            printf(" %d %d", a, c);
        }
        else{
            printf(" %d %d", c, a);
        }
    }
    else{
        printf("%d", c);
        if (a < b){
            printf(" %d %d", a, b);
        }
        else{
            printf(" %d %d", b, a);
        }
    }
    printf("\n");
}

int main(){
    int a, b, c;
    printf("Digite 3 numeros: "); scanf("%d %d %d", &a, &b, &c);
    ord3(a, b, c);
    return 0;
}
