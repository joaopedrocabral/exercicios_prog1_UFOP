#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int *vetor;
    int tam;

    printf("\nDigite o tamanho do vetor: ");
    scanf(" %d", &tam);

    vetor = malloc(tam * sizeof(int));

    srand(time(NULL));

    for(int i = 0; i < tam; i++){
        *(vetor + i) = rand() % 100;
    }

    printf("\n");

    for(int i = 0; i < tam; i++){
        printf("%d ", *(vetor + i));
    }

    free(vetor);
    return 0;
}