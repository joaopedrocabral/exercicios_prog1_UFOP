#include <stdio.h>
#include <stdlib.h>

void inverter_vetor(int *vetor, int tam){
    for(int i = 0; i < (tam/2); i++){
        int temp = *(vetor + i);
        *(vetor + i) = *(vetor + (tam - 1 - i));
        *(vetor + (tam - 1 - i)) = temp;
    }
}

int main(){
    int *vetor;
    int tam;

    printf("\nDigite o tamanho vetor: ");
    scanf(" %d", &tam);

    vetor = malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
        printf("\nDigite um valor: ");
        scanf(" %d", vetor + i);
    }

    inverter_vetor(vetor, tam);

    printf("\nVetor Invertido: \n");

    for(int i = 0; i < tam; i++){
        printf("%d ", *(vetor + i));
    }

    free(vetor);
    return 0;
}