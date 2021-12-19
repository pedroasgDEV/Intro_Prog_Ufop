/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

//Bibliotecas
#include <stdio.h>
#include <string.h>

//Arquivos cabeçaçho
#include "functions.h"

void read(char arquivo[100]){
    FILE *txt = fopen(arquivo, "r"); //Abrindo arquivo a ser lido
    char temp[1000]; //string temporaria
    char resp;

    while (1){
        fgets(temp, 1000, txt);
        if(strcmp(temp, "#end") == 0){break;} //caso o arquivo tenha terminado
        printf("%s", temp);
    }
    getchar(); scanf("%c", &resp);
    fclose(txt);
}
