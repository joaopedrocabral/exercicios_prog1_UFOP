#include <stdio.h>
#include <stdlib.h>

int buscar_valor(int **matriz, int lin, int col, int valor){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            if(matriz[i][j] == valor){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int **matriz;
    int lin, col;

    printf("\nDigite o número de linhas: ");
    scanf(" %d", &lin);

    printf("\nDigite o número de colunas: ");
    scanf(" %d", &col);

    matriz = malloc(lin * sizeof(int*));

    if(matriz == NULL){
        printf("\nErro de alocação!\n");
        return 1;
    }

    for(int i = 0; i < lin; i++){
        matriz[i] = malloc(col * sizeof(int));

        if(matriz[i] == NULL){
            printf("\nErro de alocação!\n");
            return 1;
        }
    }

    printf("\nDigite os valores da matriz:\n");

    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("Elemento [%d][%d]: ", i, j);
            scanf(" %d", &matriz[i][j]);
        }
    }

    int valor;
    printf("\nDigite o valor que deseja buscar: ");
    scanf(" %d", &valor);

    if(buscar_valor(matriz, lin, col, valor)){
        printf("\nValor encontrado na matriz!\n");
    } else {
        printf("\nValor não encontrado.\n");
    }

    for(int i = 0; i < lin; i++){
        free(matriz[i]);
    }

    free(matriz);

    return 0;
}
