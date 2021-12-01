//Bibliotecas
#include <stdio.h>
#include <string.h>

#define t_str 100

void retira(char str[], int x);

void retira(char str[], int x){
    for (int i = 0; i < x; i++){
        for (int j = i + 1; j < x; j++){
            if(str[i] == str[j]){
                str[j] = ' ';
            }
        }
    }
}

int main(){
    char str[t_str];
    fgets(str, t_str, stdin);
    int x =  strlen(str); str[x - 1] = '\0';
    x--;
    retira(str, x);
    printf("%s\n", str);
}