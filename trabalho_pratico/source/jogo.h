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
    char **palavras; //Palavras
    int wrds; //Quantidade de palavras
    int **wrdsspot; //posição das palavaras na matriz
    int nivel; //Dificuldade do jogo
} jogo;

void cria_jogo(FILE *arquivo, int nivel);
jogo gera_matriz(jogo game, int nivel);
//int gera_coordenadas(char ***matriz, int m , int n, char palavra[], int **coordenadas, int nivel);

#endif