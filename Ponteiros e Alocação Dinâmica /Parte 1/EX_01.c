#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int x = 0;
    int *p;
    p = &x;

    printf("\nValor de X antes da atribuição: %d", x);

    srand(time(NULL));

    *p = rand() % 10;

    printf("\nValor de X após atribuição: %d", x);

    return 0;
    
}