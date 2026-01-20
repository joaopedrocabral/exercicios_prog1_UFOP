#include <stdio.h>
#include <stdlib.h>

void valores(int a, int b, int c, int *maior, int *menor){
    *maior = a;
    *menor = a;

    if(b > *maior) *maior = b;
    if(b < *menor) *menor = b;

    if(c > *maior) *maior = c;
    if(c < *menor) *menor = c;
}

int main(){
    int a, b, c;
    int maior, menor;

    printf("\nDIGITE OS VALORES PARA (a, b, c): ");
    scanf("%d %d %d", &a, &b, &c);

    valores(a, b, c, &maior, &menor);

    printf("\nO MAIOR VALOR E (%d) E O MENOR VALOR E (%d)", maior, menor);

    return 0;
}