//Bibliotecas 
#include <stdio.h>
#include <string.h>

//Tamanho matrizes
#define t_max 100

//Prototipo das funções
void scan(char arquivo[], int matriz[][t_max], int *c, int *l);
void print(char arquivo[], int matriz[][t_max], int c, int l);

//Funções
void scan(char arquivo[], int matriz[][t_max], int *c, int *l){
    FILE *input = fopen(arquivo, "r");
    
    //pega as dimensões das matrizes
    fscanf(input, "%d", l);
    fscanf(input, "%d", c);

    for(int i = 0; i < *l; i++){
        for(int j = 0; j < *c; j++){
            fscanf(input, "%d", &matriz[i][j]);
        }
    }

    fclose(input);
}

void print(char arquivo[], int matriz[][t_max], int c, int l){
    FILE *input = fopen(arquivo, "w");

    fprintf(input, "%d %d\n", c, l);

    for(int i = 0; i < c; i++){
        for(int j = 0; j < l; j++){
            if(j > 0){fprintf(input, " ");}
            fprintf(input, "%d", matriz[j][i]);
        }
        fprintf(input, "\n");
    }

    fclose(input);
}

int main(int argc, char **argv){
    int matriz[t_max][t_max];
    int c, l;

    scan(argv[1], matriz, &c, &l);
    print(argv[2], matriz, c, l);

    return 0;
}