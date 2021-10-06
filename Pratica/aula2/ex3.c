/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

/*
Questão 03 (opcional)
Crie um programa com uma variável global do tipo char e leia o conteúdo da mesma. Crie também
uma função sem parâmetros que determina se o conteúdo da variável global é uma consoante ou não.
Imprima o resultado na tela.
*/

//Bibliotecas
#include <stdio.h>

//Prototipo da função que ira analisar se a letra ́e uma consoante ou não
void consoante();

//Variavel global
char letra;

int main(){
    //Função que ira analisar se a letra ́e uma consoante ou não
    void consoante(){
        switch (letra){
            //Se caso a variavel for vogal 
            case 'A': case 'E': case 'I': case 'O': case 'U':
            case 'a': case 'e': case 'i': case 'o': case 'u':
                printf("'%c' não é uma consoante\n", letra);//Saida
                break;
            default:
                //Se caso a variavel for um simbolo usando a tabela ASCII
                if ((letra < 'A') || ((letra > 'Z') && (letra < 'a')) || (letra > 'z')){
                    printf("'%c' não é uma consoante\n", letra);//Saida
                }

                //Se caso a variavel for uma consoante
                else{
                    printf("'%c' é uma consoante\n", letra);//Saida
                }
                break;
        }
    }

    //Entrada
    printf("Digite somente uma letra: "); scanf("%c", &letra);
    consoante();
    return 0;
}