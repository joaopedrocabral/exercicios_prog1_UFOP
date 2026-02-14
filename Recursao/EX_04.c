#include <stdio.h>
#include <stdlib.h>

int contar(int n){
    if( n < 10){
        return 1;
    } else {
        return 1 + contar(n / 10);
    }
}

int main(){
    int n;

    printf("\nDigite um valor: ");
    scanf(" %d", &n);

    printf("\n Resultado = %d\n",contar(n));
    
    return 0;
}  