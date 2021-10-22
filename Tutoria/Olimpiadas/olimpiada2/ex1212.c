//Bibliotecas
#include <stdio.h>
#include <math.h>
 
int main() {
    //Variaveis
    int num1, num2, carry;
    int i = 1;

    while (1){
        printf("Digite dois numeros para adição: "); scanf("%d %d", &num1, &num2);//Entrada

        if(num1 == 0 && num2 == 0){break;} //valores de saida

        do{ //Laço de processamento
            if(num1 % (int) pow(10, i) + num2 % (int) pow(10,i) >= (int) pow(10, i)){ //divide o numero e soma para ver se tem carry
                carry++;
            }
            i++;
        }while(i <= 9);

        i=0;
        printf("%d carry operations\n", carry);//Saida
        carry = 0;
    }
    
}