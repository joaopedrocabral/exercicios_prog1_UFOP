#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int matriz[5][5];

    int cont = 0;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            matriz[i][j] = rand();

            if(matriz[i][j] != 0){
                cont++;
            }
        }
    }

    printf("\nNUMERO DE POSICOES NAO NULAS: %d", cont);

    return 0;
}