#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int soma_dobro(int *a, int *b){
    *a = 2*(*a);
    *b = 2*(*b);

    return *a + *b;
}

int main(){
    srand(time(NULL));

    int a = rand() % 10;
    int b = rand() % 10;

    printf("\n(a) = %d\n(b) = %d\n", a, b);

    printf("Soma do Dobro = %d\n", soma_dobro(&a, &b));

    return 0;
}