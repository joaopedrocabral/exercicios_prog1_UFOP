#include <stdio.h>
#include <stdlib.h>

int main(){
    int numPositivo, numNegativo, numTemporario;

    printf("\nDigite um número:");
        scanf("%d", &numTemporario);

    if (numTemporario > 0){
        numPositivo = numTemporario;
        printf("\nO numero digitado e positivo: %d", numPositivo);
    
    }else if (numTemporario < 0){
        numNegativo = numTemporario;
        printf("\nO numero digitado e negativo: %d", numNegativo);
    }

    return 0;
