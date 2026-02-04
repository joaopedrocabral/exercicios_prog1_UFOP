#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerar_matriz(int matriz[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matriz[i][j] = rand() %10;
        }
    }
}

void exibir_matriz(int matriz[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void exibir_matriz_girada(int matriz[3][3]){
    for(int j = 0; j < 3; j++){
        for(int i = 2; i >= 0; i--){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int matriz[3][3];
    
    printf("\nMatriz Original:\n");

    srand(time(NULL));

    gerar_matriz(matriz);

    exibir_matriz(matriz);

    printf("\nMatriz Girada em 90º:\n");

    exibir_matriz_girada(matriz);

    return 0;

}