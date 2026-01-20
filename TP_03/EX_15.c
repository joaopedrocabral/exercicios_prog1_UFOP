#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a, b;

    printf("\nDIGITE UM VALOR PARA (a): ");
    scanf("%d", &a);

    printf("\nDIGITE UM VALOR PARA (b): ");
    scanf("%d", &b);

    troca(&a, &b);

    printf("\nVARIAVEIS COM OS VALORES TROCADOS:");
    printf("\nA = %d", a);
    printf("\nB = %d", b);

    return 0;
}