#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void copia_vetor(int *vet1, int *vet2, int tam){
    for(int i = 0; i < tam; i++){
        *(vet2 + i) = *(vet1 + i);
    }
}

int main(){
    int *vet1;
    int *vet2;
    int tam;

    printf("\nDigite o tamanho dos vetores: ");
    scanf(" %d", &tam);

    vet1 = malloc(tam * sizeof(int));
    vet2 = malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
        *(vet1 + i) = rand() % 100;
        *(vet2 + i) = rand() % 50;
    }

    printf("\nVETORES PREENCHIDOS:\n");

    for(int i = 0; i < tam; i++){
        printf("%d ", *(vet1 + i));
    }

    printf("\n\n");

    for(int i = 0; i < tam; i++){
        printf("%d ", *(vet2 + i));
    }

    copia_vetor(vet1, vet2, tam);

    printf("\n\nVETORES COPIADOS:\n");

    for(int i = 0; i < tam; i++){
        printf("%d ", *(vet1 + i));
    }

    printf("\n\n");

    for(int i = 0; i < tam; i++){
        printf("%d ", *(vet2 + i));
    }

    free(vet1);
    free(vet2);
    return 0;
}