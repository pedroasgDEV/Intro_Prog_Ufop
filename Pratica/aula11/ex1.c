/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

int main(){
    //Variaveis
    int n, sub_med = 0;
    double media = 0;

    //Entrada da dimenção do vetor
    printf("Digite o valor de n: "); scanf("%d", &n);

    //Criando vetor dinamico
    int *vet1 = malloc(n * sizeof(int));

    //Entrada do vetor
    printf("Digite os valores do vetor: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &vet1[i]);
        media += vet1[i]; //Soma os valores na media
    }

    media /= n; //tira a media
    printf("A média é: %.2lf\n", media);

    //tamanho dos dois outros vetores
    for(int i = 0; i < n; i++){
        if(vet1[i] < media){
            sub_med++;
        }
    }

    //Vetor dinamico de numeros abaixo da media
    int *vet2 = malloc(sub_med * sizeof(int));

    //Vetor dinamico de numeros acima ou na media
    int *vet3 = malloc((n - sub_med) * sizeof(int));

    
    //Entrada dos vetores
    for(int i = 0, j = 0, k = 0; i < n; i++){
        if(vet1[i] < media){
            vet2[j] = vet1[i];
            j++;
        }
        else{
            vet3[k] = vet1[i];
            k++;
        }
    }

    printf("Vetor que possui %d valores abaixo da média: [ ", sub_med);
    for(int i = 0; i < sub_med; i++){
        printf("%d ", vet2[i]);
    }
    printf("]\n");

    printf("Vetor que possui %d valores iguais ou acima da média: [ ", n - sub_med);
    for(int i = 0; i < (n - sub_med); i++){
        printf("%d ", vet3[i]);
    }
    printf("]\n");


    free(vet1);
    free(vet2);
    free(vet3);

    return 0;
}