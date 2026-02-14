#include <stdio.h>
#include <stdlib.h>

void contar_negativos(int *vetor, int tam, int *qtd_negativos){
    for(int i = 0; i < tam; i++){
        if(*(vetor + i) < 0){
            (*qtd_negativos)++;
        }
    }
}

int main(){
    int *vetor;
    int tam, qtd_negativos = 0;

    printf("\nDigite o tamanho do vetor: ");
    scanf(" %d", &tam);

    vetor = calloc(tam, sizeof(int));

    if(vetor != NULL){
        for(int i = 0; i < tam; i++){
            printf("\nDigite um valor: ");
            scanf(" %d", vetor + i);
        }

        contar_negativos(vetor, tam, &qtd_negativos);

        printf("\nQuantidade de números negativos: %d", qtd_negativos);

    } else {
        printf("\nErro de alocação de memória!\n");
    }

    free(vetor);
    return 0;
}