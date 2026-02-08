#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b;

    if(&a > &b){
        printf("\nO endereço de (a) é maior = %p\n", (void*)&a);

    } else if(&b > &a){
        printf("\nO endereço de (b) é maior = %p\n", (void*)&b);

    } 

    return 0;
}
