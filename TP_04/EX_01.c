#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void preencher_matriz(int matriz[3][5]){
    srand(time(NULL));

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            matriz[i][j] = rand() % 10;
        }
    }

}

void exibir_matriz(int matriz[3][5]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void somar_linhas(int matriz[3][5], int vetor[3]){
    int soma = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            soma+= matriz[i][j];
        }
        vetor[i] = soma;
        soma = 0;
    }
}

int main(){
    int matriz[3][5];
    int vetor[3];

    preencher_matriz(matriz);

    printf("\nMATRIZ PREENCHIDA:\n");
    exibir_matriz(matriz);

    printf("\nVETOR:");
    somar_linhas(matriz, vetor);

    int i = 0;

    while(i < 3){
        printf("%d ", vetor[i]);
        i++;
    }

    return 0;
}