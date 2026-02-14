#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int soma_vetor(int *vetor, int n){
    int soma = 0;

    for(int i = 0; i < n; i++){
        soma += *(vetor + i);
    }

    return soma;
}

int main(){
    int *vetor;
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf(" %d", &n);

    vetor = calloc(n, sizeof(int));

    if(vetor != NULL){
        for(int i = 0; i < n; i++){
            *(vetor + i) = rand() % 100;
        }

        printf("\nSoma dos %d elementos do vetor: %d", n, soma_vetor(vetor, n));

    } else {
        printf("\nErro de alocação de memória\n");
    }

    free(vetor);
    return 0;
}