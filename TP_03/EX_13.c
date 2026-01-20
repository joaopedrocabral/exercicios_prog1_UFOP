#include <stdio.h>
#include <stdlib.h>

int maior(int n, int p){
    if(n > p){
        return n;
    } else if(p > n){
        return p;
    } else if(p==n){
        return 'a';
    }
}

int main(){
    int n, p;

    printf("\nDIGITE O PRIMEIRO NUMERO: ");
    scanf("%d", &n);

    printf("\nDIGITE O SEGUNDO NUMERO: ");
    scanf("%d", &p);

    int res = maior(n,p);

    if(res == 'a'){
        printf("\nOS NUMEROS SAO IGUAIS");
    } else {
        printf("\nO MAIOR NUMERO E: %d", res);
    }

    return 0;

}