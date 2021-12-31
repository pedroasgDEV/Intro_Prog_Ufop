/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

#ifndef LAYOUTS_H_INLCUDED
#define LAYOUTS_H_INLCUDED

//Definira qual o sistema ultilizado
#if defined(__linux__) || defined(__unix__) || defined(__Apple__)
    #define limpa "clear"
#endif
#if defined(_WIN32) || defined(_WIN64)
    #define limpa "cls"
#endif

//Bibliotecas
#include <stdio.h>


void read(char arquivo[100]);
int verifica_arqnovo(FILE *txt);
int verifica_arqsalvo(FILE *txt);
void nivel_newgame(char arquvivo[]);
void arq_newgame(int i);
void arq_continuegame();
void instructions();
void main_layout();

#endif