//Bibliotecas
#include <stdio.h>
#include <string.h>

//Vectors's size
#define t_nam 100
#define t_peo 100

//Structs
typedef struct{
    char nam[t_nam];
    float alt;
    int bth; 
} peo;

//Functions's prototypes
peo addpeo();
void print_alt(peo temp[], int x);
void print_year(peo temp[], int x);

//Functions
peo addpeo(){
    //Functions vars
    peo temp;
        
    //Struct input
    printf("Nome: ");
    getchar();
    fgets(temp.nam, t_nam, stdin); temp.nam[strlen(temp.nam) - 1] = '\0';
    printf("Altura: "); scanf("%f", &temp.alt);
    printf("Ano de nascimento: "); scanf("%d", &temp.bth);

    return temp;
}

void print_alt(peo temp[], int x){
    for(int i = 0; i < x; i++){
        printf("%s %.2f\n", temp[i].nam, temp[i].alt);
    }
}

void print_year(peo temp[], int x){
    //Functions vars
    int y; printf("Digite um ano: "); scanf("%d", &y);

    for(int i = 0; i < x; i++){
        if(temp[i].bth > y){
             printf("%s\n", temp[i].nam);
        }
    }
}

int main(){
    //Vars
    peo people[t_peo];
    int opt, x = 0;

    while (1){
        printf("\nSelecione uma opção: \n\n");
        printf("1 - Adicionar uma pessoa\n");
        printf("2 - Listar todas as pessoas e sua respectiva altura\n");
        printf("3 - Listar todas as pessoas a partir de um ano\n");
        printf("4 - Sair\n\n");
        scanf("%1d", &opt);printf("\n");

        switch (opt){
            case 1: 
                people[x] = addpeo();
                x++;
                break;
            
            case 2:
                print_alt(people, x);
                break;

            case 3:
                print_year(people, x);
                break;
            
            case 4:
                return 0;
                break;

            default:
                printf("ERRO: Digite um numero valido\n");scanf("%1d", &opt);
        }

    }
}