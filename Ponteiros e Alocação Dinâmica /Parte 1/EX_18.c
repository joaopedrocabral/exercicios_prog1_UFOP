#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char nome[100];
    int idade;
    float media;
} aluno;

void exibir_dados(aluno *lista, int tam){
    for(int i = 0; i < tam; i++){
        printf("\nDADOS DO %dº ALUNO\n", i + 1);
        printf("\nNome: %s", (*(lista + i)).nome);
        printf("\nIdade: %d", (*(lista + i)).idade);
        printf("\nMédia: %.2f\n", (*(lista + i)).media);
    }
}

int main(){
    aluno *lista;
    int tam;

    printf("\nDigite o tamanho da lista: ");
    scanf(" %d", &tam);

    lista = malloc(tam * sizeof(aluno));

    if(lista != NULL){
        for(int i = 0; i < tam; i++){
            printf("\nINFORMAÇÕES DO %dº ALUNO\n", i + 1);
            printf("\nDigite o nome: ");
            scanf(" %99[^\n]", (*(lista + i)).nome);

            printf("\nDigite a idade: ");
            scanf(" %d", &(*(lista + i)).idade);

            printf("\nDigite a média: ");
            scanf(" %f", &(*(lista + i)).media);
        }

        printf("\n");
        exibir_dados(lista, tam);

    } else {
        printf("\nErro de alocação de memória!\n");
    }
    

    free(lista);
    return 0;
}