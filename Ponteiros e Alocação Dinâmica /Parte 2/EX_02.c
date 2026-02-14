#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void maior(int *vet, int n, int *valor, int *posicao){
    *valor = *(vet);
    *posicao = 0;

    for(int i = 1; i < n; i++){
        if(*(vet + i) > *valor){
            *valor = *(vet + i);
            *posicao = i;
        }
    }
}

int main(){
    srand(time(NULL));
    int tam = rand() % 10;
    printf("\nTamanho do Vetor: %d\n", tam);

    int *vetor = calloc(tam, sizeof(int));
    int valor, posicao;

    for(int i = 0; i < tam; i++){
        *(vetor + i) = rand() % 10;
    }

    maior(vetor, tam, &valor, &posicao);

    for(int i = 0; i < tam; i++){
        printf("%d ", *(vetor + i));
    }

    printf("\nMaior Número: %d", valor);
    printf("\nPosição em Índice: %d", posicao);

    free(vetor);
    return 0;
}