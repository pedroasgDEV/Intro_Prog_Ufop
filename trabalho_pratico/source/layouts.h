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

//Prototipo das funções
void main_layout();
void arq_newgame();
void nivel_newgame(char arquvivo[]);
void continue_game();
void instructions();

#endif