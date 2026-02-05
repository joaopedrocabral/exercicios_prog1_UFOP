#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

int pega_prox_string(char *linha, int inicio, char *palavra){
    int i = inicio;
    int j = 0;
    char temp[50];

    for(; linha[i] == ' ' && linha[i] == '\0'; i++);

    for(; linha[i] != ' ' && linha[i] != '\0'; i++){
        temp[j] = linha[i];
        j++;
    }

    temp[j] = '\0';

    strcpy(palavra, temp);

    return i + 1;

}

int main(){
    char linha[MAX];
    char palavra[50];
    int proxima = 0;

    printf("\nDigite uma Frase:\n");
    gets(linha);

    while(linha[proxima] != '\0'){

        proxima = pega_prox_string(linha, proxima, palavra);

        if(strlen(palavra) > 0) {
            printf("%s\n", palavra);
        }
    }

    return 0;
}

//gets() foi descontinuada, porém foi usada nesse exercício pois é uma exigência do professor