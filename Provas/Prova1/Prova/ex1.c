#include <stdio.h>

double p(double F, double A);

double p(double F, double A){
    return F/A;
} 
int main(){
    double F,A;
    printf("Digite o valor da força e da area: ");
    scanf("%lf %lf", &F, &A);
    printf("A pressão é %lf\n", p(F, A));
    return 0;
}