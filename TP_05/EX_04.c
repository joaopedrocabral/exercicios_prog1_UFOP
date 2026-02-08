#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int soma_vetor(int vetor[], int tam){

    if(tam == 0){
        return 0;
    }

    return vetor[tam-1] + soma_vetor(vetor, tam - 1);
}


int main(){
    int vetor[10];

    srand(time(NULL));

    for(int i = 0; i < 10; i++){
        vetor[i] = rand() % 10;
    }

    for(int i = 0; i < 10; i++){
        printf("%d ", vetor[i]);
    }

    printf("\nSoma dos elementos do vetor = %d", soma_vetor(vetor, 10));

    return 0;
}