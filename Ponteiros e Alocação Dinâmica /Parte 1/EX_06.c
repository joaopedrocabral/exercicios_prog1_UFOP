#include <stdio.h>
#include <stdlib.h>

void verificar_negativos(int *vetor, int *qtd_negativos){
    for(int i = 0; i < 10; i++){
        if(*(vetor + i) < 0){
            (*qtd_negativos)++;
        }
    }
}

int main(){
    int vetor[10] = {-54, -32, 14, -19, 25, 89, -45, -98, -75, -100};

    int qtd_negativos = 0;

    verificar_negativos(vetor, &qtd_negativos);

    printf("\nExistem %d números negativos no vetor\n", qtd_negativos);
}