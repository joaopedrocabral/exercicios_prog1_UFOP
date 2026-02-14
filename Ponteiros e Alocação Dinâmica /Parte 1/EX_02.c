#include <stdio.h>
#include <stdlib.h>

int main(){

    int x = 2;
    int *y;

    y = &x;

    printf("Valor da Variável: %d\n", x);
    printf("End da Variável: %p\n", (void*)&x);

    printf("\nValor do Ponteiro: %p\n", y);
    printf("Valor apontado: %d", *y);

    return 0;
}