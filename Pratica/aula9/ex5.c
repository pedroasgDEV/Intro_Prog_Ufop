/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/
#include <stdio.h>
#include <string.h>

//Vectors's size
#define t_nam 100 //tamnho maximo dos nomes
#define t_aln 100 //quantidade maxima de alunos
#define t_txt 100 //tamnho maximo do caminho do arquivo
#define nota_apro 6.0 //nota minima de aprovaçãp
#define freq_apro 60.0 //frequencia minima de aprovação


//Structs
typedef struct{
    char nam[t_nam];
    float nota;
    float freq; 
} Aluno;

//Prototipo das funções
double media_nota(Aluno temp[], int n);
double media_freq(Aluno temp[], int n);
double aprov(Aluno temp[], int n);
void print_bin(char file[], Aluno temp[], int n);

//Funções
double media_nota(Aluno temp[], int n){
    double media = 0;
    
    for(int i = 0; i < n; i++){
        media += temp[i].nota;
    }

    return media/n;
}

double media_freq(Aluno temp[], int n){
    double media = 0;
    
    for(int i = 0; i < n; i++){
        media += temp[i].freq;
    }

    return media/n;
}

double aprov(Aluno temp[], int n){
    double aprov = 0;

    for(int i = 0; i < n; i++){
        if((temp[i].nota >= nota_apro) && (temp[i].freq >= freq_apro)){
            aprov++;
        }
    }

    return (aprov/n) * 100; //Retorna em porcentagem
}

//Grava os dados em um arquivo binario
void print_bin(char file[], Aluno temp[], int n){
    FILE *input = fopen(file, "wb");

    fwrite(&n, sizeof(int), 1, input);

    for (int i = 0; i < n; i++){
        fwrite(&temp[i], sizeof(Aluno), 1, input);
    }

    fclose(input);
}



int main(){
    //Variaveis
    char file[t_txt];
    Aluno aluno[t_aln], aluno_bin[t_aln];
    int n;
    double med_nota, med_freq, apv;

    //Nome do arquivo de entrada
    printf("Digite o nome do arquivo: ");
    fgets(file, t_nam, stdin); file[strlen(file) - 1] = '\0';

    //Leitura do arquivo
    FILE *input = fopen(file, "r");

    //pega as dimensões das matrizes
    fscanf(input, "%d", &n);

    for(int i = 0; i < n; i++){
        //Pega o nome
        fgetc(input); fgets(aluno[i].nam, t_nam, input); aluno[i].nam[strlen(aluno[i].nam) - 1] = '\0';

        //Pega a nota e a frequencia
        fscanf(input, "%f %f", &aluno[i].nota, &aluno[i].freq);
    }

    fclose(input);

    //Nome do arquivo de gravção
    printf("Digite o nome do arquivo de gravação: ");
    fgets(file, t_nam, stdin); file[strlen(file) - 1] = '\0';

    //Criação do arquivo de gravaçãp
    print_bin(file, aluno, n);

    //Leitura do arquivo binario
    FILE *input_bin = fopen(file, "rb");

    //pega as dimensões das matrizes
    fread(&n, sizeof(int), 1, input_bin);

    for(int i = 0; i < n; i++){
        fread(&aluno_bin[i], sizeof(Aluno), 1, input_bin);
    }

    fclose(input_bin);
    
    //Processamento
    med_nota = media_nota(aluno_bin, n);
    med_freq = media_freq(aluno_bin, n);
    apv = aprov(aluno_bin, n);

    //Saidas
    printf("Nota média: %.2lf\n", med_nota);
    printf("Frequencia média(porcentagem): %.2lf\n", med_freq);
    printf("Porcentagem de aprovação(porcentagem): %.2lf\n", apv);

    printf("\nNomes dos alunos com nota acima da nota média:\n");
    for(int i = 0; i < n; i++){
        if(aluno_bin[i].nota > med_nota){
            printf("%s\n", aluno_bin[i].nam);
        }
    }

    return 0;
}
