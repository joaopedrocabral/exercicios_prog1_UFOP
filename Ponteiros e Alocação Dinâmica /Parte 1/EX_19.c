#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int qtd;
    float *notas;
} turma;

int main(){
    turma turma;
    float soma = 0;

    printf("\nDigite a quantidade de alunos: ");
    scanf(" %d", &turma.qtd);

    turma.notas = malloc(turma.qtd * sizeof(float));

    srand(time(NULL));

    if(turma.notas != NULL){
        for(int i = 0; i < turma.qtd; i++){
            turma.notas[i] = ((float)rand() / RAND_MAX) * (100 - 30);
        }
        

    } else {
        printf("\nErro de alocação!\n");
        return 1;
    }

    for(int i = 0; i < turma.qtd; i++){
        soma += turma.notas[i];
    }

    printf("\nMédia da Turma: %.2f", soma/turma.qtd);

    free(turma.notas);
    return 0;
}