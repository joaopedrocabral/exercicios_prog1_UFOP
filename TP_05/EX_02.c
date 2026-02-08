#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x;
    float y;
    float z;
} vetor;

void preencher_vetor(vetor *vetor){
    printf("\nDigite o X do vetor: ");
    scanf(" %f", &vetor->x);

    printf("\nDigite o Y do vetor: ");
    scanf(" %f", &vetor->y);

    printf("\nDigite o Z do vetor: ");
    scanf(" %f", &vetor->z);
}

void soma_vetores(vetor vetor1, vetor vetor2, vetor *resultado){
    resultado->x = vetor1.x + vetor2.x;
    resultado->y = vetor1.y + vetor2.y;
    resultado->z = vetor1.z + vetor2.z;
}

void exibir_vetor(vetor vetor){
    printf("(%.2f, %.2f, %.2f)", vetor.x, vetor.y, vetor.z);
}

int main(){
    vetor vetor1;
    vetor vetor2;
    vetor vetor_soma;

    printf("\nPrimeiro Vetor\n");
    preencher_vetor(&vetor1);

    printf("\nSegundo Vetor\n");
    preencher_vetor(&vetor2);

    printf("\nSoma dos vetores:\n");
    soma_vetores(vetor1, vetor2, &vetor_soma);
    exibir_vetor(vetor_soma);

    return 0;
}