#include <stdio.h>
#include <stdlib.h>

int main(){
    int vetor[10] = {07, 52, 89, 64, 35, 74, 46, 31, 28, 11};

    int *p = vetor;

    for(int i = 0; i < 10; i++){
        printf("%d ", *p);
        p++;
    }

    return 0;
}