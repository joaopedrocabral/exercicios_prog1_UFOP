#include <stdio.h>
#include <stdlib.h>

void inverter(int *vetor, int tam){
    int vetor_invertido[tam];
    int j = 0;

    for(int i = tam - 1; i >= 0; i--){
        *(vetor_invertido + j) = *(vetor + i);
        j++;
    }

    for(int i = 0; i < tam; i++){
        *(vetor + i) = *(vetor_invertido + i);
    }
}


int main(){
    int vetor[3] = {1, 2, 3};

    inverter(vetor, 3);

    for(int i = 0; i < 3; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}