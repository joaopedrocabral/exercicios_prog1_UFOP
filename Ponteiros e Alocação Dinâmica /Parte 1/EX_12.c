#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vetor;
    int tam;

    printf("\nDigite um o tamanho do vetor: ");
    scanf(" %d", &tam);

    vetor = calloc(tam, sizeof(int));

    if(vetor != NULL){
        for(int i = 0; i < tam; i++){
        printf("%d ", *(vetor + i));
        }

    } else {
        printf("\nErro de alocação de memória");
    }

    free(vetor);
    return 0;
}