#include <stdio.h>
#include <stdlib.h>

int potencia(int base, int expoente){
    if(expoente == 0){
        return 1;
    } else {
        return base * potencia(base, expoente  - 1);
    }
}

int main(){
    int base, expoente;

    printf("\nDigite a base: ");
    scanf(" %d", &base);

    printf("\nDigite o expoente: ");
    scanf(" %d", &expoente);

    printf("\nResultado de %d elevado a %d = %d", base, expoente, potencia(base, expoente));

    return 0;     
}