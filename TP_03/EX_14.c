#include <stdio.h>
#include <stdlib.h>

int divisor(int x, int y){
    int cont = 0;
    while(x%y==0){
        x /= y;
        cont++;
    }

    if(cont == 0) return -1;

    return cont;
}

int main(){
    int x,y;

    printf("\nDIGITE X e Y: ");
    scanf("%d %d", &x, &y);

    int res = divisor(x,y);

    if(res != -1){
        printf("\n%d DIVISIVEL POR %d %d VEZES", x, y, res);
    } else {
        printf("\n%d NAO E DIVISIVEL POR %d", x, y);
    }

    return 0;

}