//Bibliotecas 
#include <stdio.h>

int main(){
    //Variaveis :(
    int idade;

    //Funções
    //Função de verificação de classe eleitoral
    void eleitoral(int idade){
        if (((idade >= 16) && (idade < 18)) || (idade >= 65)){
            printf("Você não precisa votar\n");//Saida
        };
        if ((idade >= 18) && (idade < 65)){
            printf("Você precisa votar\n");//Saida
        };
        if (idade < 16){
            printf("Você não pode votar\n");//Saida
        }
    }

    //Entrada
    printf("digite sua idade: "); scanf("%d", &idade);
    
    //Processamento
    eleitoral(idade);

    return 0;
}