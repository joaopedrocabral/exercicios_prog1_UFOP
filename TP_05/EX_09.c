#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vetor;
    vetor = calloc(1500, sizeof(int));
    int zeros = 0;

    if(vetor == NULL){
        printf("\nErro de alocação de memória!\n");
        return 1;
    }

    for(int i = 0; i < 1500; i++){
        if(vetor[i] == 0){
            zeros++;
        }
    }

    for(int i = 0; i < 1500; i++){
        if(vetor[i] == 0){
            vetor[i] = i;
        }
    }

    printf("\nO vetor possui %d zeros", zeros);

    printf("\nPrimeiros 10 elementos:\n");

    for(int i = 0; i < 10; i++){
        printf("%d ", vetor[i]);
    }

    printf("\nUltimos 10 elementos:\n");

    for(int i = 1490; i < 1500; i++){
        printf("%d ", vetor[i]);
    }

    free(vetor);

    return 0;

}