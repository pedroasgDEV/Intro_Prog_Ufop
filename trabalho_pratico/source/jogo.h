/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

#ifndef JOGO_H_INLCUDED
#define JOGO_H_INLCUDED

//Bibliotecas
#include <stdio.h>

//Prototipo das funções
typedef struct {
    char matriz[26][26];
    int m, n; //Dimensões da matriz
    char palavras[26][27]; //Palavras
    int wrds; //Quantidade de palavras
    int wrdsspot[26][4]; //Coordenadas das palavaras na matriz
    int wrdsspot_ok[48][26]; //Coordenadas das palavaras encontradas pelo usuario
    int nivel; //Dificuldade do jogo
} jogo;

void cria_jogo(char arquvivo[], int nivel);
jogo gera_matriz(jogo game, int nivel);
void play_jogo(jogo game);

#endif