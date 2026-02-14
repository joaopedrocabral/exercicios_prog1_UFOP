#include <stdio.h>
#include <stdlib.h>

int main(){
    int var = 10;

    printf("Valor Original da Variável: %d\n", var);

    int *pont = &var;

    int **ppont = &pont;

    printf("\nDigite um novo valor: ");
    scanf("%d", *ppont);

    printf("Valor da Variável após alteração: %d", **ppont);

    return 0;
}