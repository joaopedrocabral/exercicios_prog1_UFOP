#include <stdio.h>
#include <stdlib.h>

int fatorial(int n){
    if(n == 0 || n == 1){
        return 1;
    } else {
       return n * fatorial(n-1);
    }
}

int main(){
    int n;

    printf("\nDigite um valor: ");
    scanf(" %d", &n);

    printf("\n Fatorial de %d = %d\n", n, fatorial(n));
    
    return 0;
} 