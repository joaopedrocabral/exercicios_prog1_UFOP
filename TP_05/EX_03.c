#include <stdio.h>
#include <stdlib.h>

int F(int n){
    
    if(n == 1){
        return 1;
    }

    if (n == 2){
        return 2;
    }

    return 2 * F(n - 1) + 3 * F(n -2);
}

int main(){
    int n;

    printf("\nDigite um número: ");
    scanf(" %d", &n);

    printf(" %d", F(n));

    return 0;
}