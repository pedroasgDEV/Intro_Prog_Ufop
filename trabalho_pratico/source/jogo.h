/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

#ifndef JOGO_H_INLCUDED
#define JOGO_H_INLCUDED

//Bibliotecas
#include <stdio.h>

//Struct do jogo
typedef struct {
    char matriz[26][26]; //Matriz do caça-palavras
    int m, n; //Dimensões da matriz
    char palavras[26][27]; //Palavras
    int wrds; //Quantidade de palavras
    int wrdsspot[26][4]; //Coordenadas das palavaras na matriz
    int wrdsspot_ok[26][4]; //Coordenadas das palavaras encontradas pelo jogador
    int nivel; //Dificuldade do jogo
    int acertos; //A quantidade de palavras encontradas
} jogo;

//Prototipo das funções
jogo gera_matriz(jogo game, int nivel);
jogo resolve(jogo game);
void salva_jogo(char arquivo[], jogo game);
void play_jogo(jogo game);
void carrega_jogo(char arquivo[]);
void cria_jogo(char arquvivo[], int nivel);


#endif