#include <stdio.h>
#include <stdlib.h>

int divisao(int a, int b, int *div, int *mod){
    if(b == 0) return -1;

    *div = a/b;
    *mod = a%b;

    return 0;
}

int main(){
    int a, b, div, mod;

    printf("\nDIGITE OS VALORES PARA (a) e (b): ");
    scanf("%d %d", &a, &b);

    if(divisao(a, b, &div, &mod) != -1){
        printf("\nDIV = %d e MOD = %d", div, mod);
    } else {
        printf("\nDIVISAO INVALIDA!");
    }

    return 0;
}