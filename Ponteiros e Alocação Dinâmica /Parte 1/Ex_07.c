#include <stdio.h>
#include <stdlib.h>

void encontrar_maior(int *vetor, int tam, int *maior_valor){
    *maior_valor = *vetor;

    for(int i = 1; i < tam; i++){
        if(*(vetor + i) > *maior_valor){
            *maior_valor = *(vetor + i);
        }
    }

}


int main(){
    int vetor[10] = {23, 99, 56, 85, 106, 299, 145, 564, 3, 9};
    int maior_valor;

    encontrar_maior(vetor, 10, &maior_valor);

    printf("\nO maior valor é: %d", maior_valor);

    return 0;
}