/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

/*
Questão 03
Faça um programa que lê do usuário a hora de inı́cio e a hora de término de um jogo, ambas subdi-
vididas em 2 valores distintos: hora e minuto.
Em seguida implemente uma função que recebe estes dados por ponteiros e retorna a duração do jogo
em minutos. Note que o jogo pode começar em um dia e terminar no outro.
Finalmente, imprima a duração total do jogo (na função main()) em minutos.
*/

//Bibliotecas
#include <stdio.h>

//Prototipo da função que ira calcular a duração do jogo
void calculaDuracao(int hora_inicio, int minuto_inicio, int hora_final, int minuto_final, int *duracao);

int main(){
    //Variaveis
    int hora_inicio, hora_final, minuto_inicio, minuto_final, duracao;


    //Função que ira calcular a duração do jogo
    void calculaDuracao(int *hora_inicio, int *minuto_inicio, int *hora_final, int *minuto_final, int *duracao){ 

        if ((*hora_inicio * 60) + *minuto_inicio < (*hora_final * 60) + *minuto_final){//Se acabar no mesmo dia
            *duracao = ((*hora_final * 60) + *minuto_final) - ((*hora_inicio * 60) + *minuto_inicio);
        }
        else{//Se acabar no outro dia
            *duracao = ((24 * 60) - ((*hora_inicio * 60) + *minuto_inicio)) + ((*hora_final * 60) + *minuto_final);
        }
    }

    //Entrada
    printf("Digite a hora que o jogo começou: "); scanf("%d", &hora_inicio); //Entrada da hora do inicio do jogo
    printf("Digite o minuto que o jogo começou: "); scanf("%d", &minuto_inicio); //Entrada do minuto do inicio do jogo
    printf("Digite a hora que o jogo acabou: "); scanf("%d", &hora_final); //Entrada da hora do final do jogo
    printf("Digite o minuto que o jogo acabou: "); scanf("%d", &minuto_final); //Entrada do minuto do final do jogo

    //Processamento
    calculaDuracao(&hora_inicio, &minuto_inicio, &hora_final, &minuto_final, &duracao);

    //Saida
    printf("O jogo durou: %d minutos\n", duracao); //Saida da duração do jogo
    return 0;
}