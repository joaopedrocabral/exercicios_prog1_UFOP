#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(){
    char palavra1[10];
    char palavra2[10];
    char palavra3[20];
    char palavra4[10];
    char palavra5;

    printf("\nDigite a 1ª Palavra:\n");
    scanf(" %9[^\n]", palavra1);

    printf("\nDigite a 2ª Palavra:\n");
    scanf(" %9[^\n]", palavra2);

    if(strcmp(palavra1, palavra2) == 0){
        printf("\nAs palavras são iguais!\n");
    } else {
        printf("\nAs palavras são diferentes!\n");
    }

    printf("\nPALAVRAS ANTES DA COPIA\n");
    printf("\nPrimeira Palavra: %s", palavra1);
    printf("\nSegunda Palavra: %s\n", palavra2);

    strcpy(palavra1, palavra2);

    printf("\nPALAVRAS DEPOIS DA COPIA\n");
    printf("\nPrimeira Palavra: %s", palavra1);
    printf("\nSegunda Palavra: %s\n", palavra2);

    printf("\nDigite a 3ª Palavra:\n");
    scanf(" %9[^\n]", palavra3);

    printf("\nDigite a 4ª Palavra:\n");
    scanf(" %9[^\n]", palavra4);

    strcat(palavra3, palavra4);

    printf("\n\nPALAVRAS CONCATENADAS (p3 + p4)\n");
    printf("\n%s", palavra3);

    printf("\nA 1ª Palavra tem %lu caracteres.\n", strlen(palavra1));

    printf("\nDigite a 1 Caractere Palavra:\n");
    scanf(" %c", &palavra5);

    if(isdigit(palavra5) == 0){
        printf("\nNão tem números\n");
    } else {
        printf("\nTem números\n");
    }

    return 0;
}