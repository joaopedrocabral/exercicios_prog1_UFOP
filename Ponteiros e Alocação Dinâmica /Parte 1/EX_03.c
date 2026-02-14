#include <stdio.h>
#include <stdlib.h>

int soma(int **c, int **d){
    int res_soma = **c + **d;

    return res_soma;
}

int main(){
    int a = 2;
    int b = 5;
    int *c = &a;
    int *d = &b;

    printf("Soma dos valores: %d", soma(&c, &d));

    return 0;
}