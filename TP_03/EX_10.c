#include <stdio.h>
#include <stdlib.h>

int capicua(int num){
    int vet[20];
    int tam = 0;
    int original = num;

    if(num < 0) return 0;
    if(num == 0) return 1;

    while(num > 0){
        vet[tam] = num%10;
        num = num/10;
        tam++;
    }

    for(int i = 0; i < (tam-1); i++){
        if(vet[i] != vet[tam-1]){
            return 0;
        } else {
            return 1;
        }
        tam --;
    }
}

int main(){
    int num;

    printf("\nDIGITE UM NUMERO: ");
    scanf(" %d", &num);

    if(capicua(num)==1){
        printf("\nE CAPICUA");
    } else {
        printf("\nNAO E CAPICUA");
    }

    return 0;
}