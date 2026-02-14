#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int *vetor;
    int tam, novo_tam;

    printf("\nDigite o tamanho para o vetor: ");
    scanf(" %d", &tam);

    vetor = malloc(tam * sizeof(int));

    if(vetor != NULL){
        srand(time(NULL));

        for(int i = 0; i < tam; i++){
            *(vetor + i) = rand() % 100;
        }

        printf("\nVetor de %d posições preenchido!\n", tam);

        printf("\nDigite o novo tamanho do vetor: ");
        scanf(" %d", &novo_tam);

        vetor = realloc(vetor, novo_tam * sizeof(int));

        if(novo_tam > tam){
            for(int i = tam; i < novo_tam; i++){
                *(vetor + i) = rand() % 100;
            }

            printf("\nVetor com o novo tamanho: \n");

            for(int i = 0; i < novo_tam; i++){
                printf("%d ", *(vetor + i));
            }

        } else {

            printf("\nO novo tamanho não é maior que o tamanho atual!\nVetor com o tamanho atual:\n");

            for(int i = 0; i < tam; i++){
                printf("%d ", *(vetor + i));
            }
        }
    } else {
        printf("\nErro de alocação de memória!\n");
    }

    free(vetor);
    return 0;
}