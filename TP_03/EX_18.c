#include <stdio.h>
#include <stdlib.h>

void encontrar_maiores(int valores[], int *segundo, int *quarto){

    for(int i = 0; i < 5; i++){
        for(int j = i+1; j < 5; j++){
            if(valores[i] > valores[j]){
                int aux = valores[i];
                valores[i] = valores[j];
                valores[j] = aux;
            }
        }
    }

    *segundo = valores[3];
    *quarto = valores[1];
}




int main(){
    int valores[5];
    int segundo, quarto;

    for(int i = 0; i < 5; i++){
        printf("\nDIGITE O VALOR INDICE [%d]: ", i);
        scanf("%d", &valores[i]);
    }

    encontrar_maiores(valores, &segundo, &quarto);

    printf("\nSEGUNDO VALOR: %d\nQUARTO VALOR: %d", segundo, quarto);

    return 0;
}