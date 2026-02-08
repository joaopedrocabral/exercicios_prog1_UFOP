#include <stdio.h>
#include <stdlib.h>
#define TAM 10

int negativos(float *vet, int N){
    int negativos = 0;

    for(int i = 0; i < N; i++){
        if(vet[i] < 0){
            negativos+= 1;
        }
    }

    return negativos;
}

int main(){
    float vet[TAM];

    for(int i = 0; i < TAM; i++){
        printf("\nDigite um valor: ");
        scanf(" %f", &vet[i]);
    }

    printf("\nO vetor possui %d números negativos\n", negativos(vet, TAM));

    return 0;
}