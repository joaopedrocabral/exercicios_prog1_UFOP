#include <stdio.h>
#include <stdlib.h>

int main(){
    int valores[5];

    for(int i = 0; i < 5; i++){
        printf("\nDigite um valor: ");
        scanf(" %d", &valores[i]);
    }

    for(int i = 0; i < 5; i++){
        if((valores[i] %2 ) == 0){
            printf("\nValor: %d\n", valores[i]);
            printf("Índice no Array: %d\n", i);
            printf("Endereço de Memória: %p\n", (void *)&valores[i]);
        }
    }

    return 0;
}