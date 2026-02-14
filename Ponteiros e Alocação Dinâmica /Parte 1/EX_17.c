#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int **matriz;
    int lin, col;

    printf("\nDigite o número de linhas da matriz: ");
    scanf(" %d", &lin);

    printf("\nDigite o número de colunas da matriz: ");
    scanf(" %d", &col);

    matriz = malloc(lin * sizeof(int*));
    
    for(int i = 0; i < lin; i++){
        matriz[i] = malloc(col * sizeof(int));
    }

    srand(time(NULL));

    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            matriz[i][j] = rand() % 100;
        }
    }

    printf("\nMATRIZ PREENCHIDA: \n");

    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < lin; i++){
        free(matriz[i]);
    }

    free(matriz);
    return 0;
}