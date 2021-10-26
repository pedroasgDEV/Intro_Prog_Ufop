#include <stdio.h>
double ordena3(int *x, int *y, int *z);
double ordena3(int *x, int *y, int *z){
    int a = *x;
    int b = *y;
    int c = *z;
    if((*x < *y) && (*x < *z)){
        if(*y > *z){
            *y = c;
            *z = b;
        }
    }
    if((*y < *x) && (*y < *z)){
        *x = b;
        if(*x < *z){
            *y = a;
        }
        else{
            *y = c;
            *z = a;
        }
    }
    if((*z < *x) && (*z < *y)){
        *x = c;
        if(*x < *y){
            *y = a;
            *z = b;
        }
        else{
            *z = a;
            *y = b;
        }
    }
    return (*x + *y + *z)/3;
}
int main(){
    int x, y, z;
    double media;
    printf("Digite 3 numeros: ");
    scanf("%d %d %d", &x, &y, &z);
    media = ordena3(&x, &y, &z);
    printf("%d %d %d\n", x, y, z);
    printf("A media é %lf\n", media);
    return 0;
}