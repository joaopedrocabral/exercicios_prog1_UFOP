#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main(){
    int a = 1, b = 3;

    printf("Valores antes da troca (a) = %d (b) = %d\n", a, b);
    
    swap(&a, &b);

    printf("Valores após a troca (a) = %d (b) = %d\n", a, b);

    return 0;
}