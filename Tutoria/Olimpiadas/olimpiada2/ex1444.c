//Bibliotecas
#include <stdio.h>
 
int main() {
    //Variaveis
    int marreco;

    while (1){
        printf("Quantidade de marrecos: "); scanf("%d", &marreco);//Entrada

        if(marreco == 0){break;} //Valor de saida do laço

        while (marreco < 2){//Erro
            printf("ERRO: Digite uma quantidade maior que 2\n");
            printf("Quantidade de marrecos: "); scanf("%d", &marreco);//Entrada
        }
        
        while (marreco % 3 != 0){//Processamento
            marreco++;
        }

        printf("Havera %d corrida(s)\n", marreco/3); //Saida

    }

    return 0;
}