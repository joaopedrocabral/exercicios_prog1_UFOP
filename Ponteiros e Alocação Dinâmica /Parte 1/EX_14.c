#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void menor_maior(int *vetor, int tam, int *menor, int *maior){
    *menor = *(vetor);
    *maior = *(vetor);

    for(int i = 1; i < tam; i++){
        if(*(vetor + i) < *menor){
            *menor = *(vetor + i);
        }

        if(*(vetor + i) > *maior){
            *maior = *(vetor + i);
        }
    }
}

int main(){
    int *vetor;
    int tam; int menor; int maior;

    printf("\nDigite o tamanho do vetor: ");
    scanf(" %d", &tam);

    vetor = malloc(tam * sizeof(int));

    if(vetor != NULL){
        srand(time(NULL));

        for(int i = 0; i < tam; i++){
            *(vetor + i) = rand() % 100;
        }

        menor_maior(vetor, tam, &menor, &maior);

        printf("\nMenor valor: %d\n", menor);

        printf("\nMaior valor: %d\n", maior);

    } else {
        printf("\nErro de alocação de memória!\n");
    }

    free(vetor);
    return 0;
}