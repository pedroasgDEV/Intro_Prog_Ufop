#include <stdio.h>
#include <math.h>

int main(){
    int x, y;
    printf("Digite dois numeros: "); scanf("%d %d", &x, &y);
    if(x == y){printf("%d", x);}
    else{
        if(x > y){printf("%.2lf %.2lf", sqrt(x), pow(y, 2));}
        else{printf("%.2lf %.2lf", pow(x, 2), sqrt(y));}
    }
    printf("\n");
    return 0;
}