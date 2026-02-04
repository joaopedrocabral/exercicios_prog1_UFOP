#include <stdio.h>
#include <stdlib.h>

void preencher_vetor(int *vetor, int tam){
    for(int i = 0; i < tam; i++){
        printf("\nDigite o %dº Valor: ", i + 1);
        scanf(" %d", &vetor[i]);
    }
}

void exibir_vetor(int *vetor, int tam){
    for(int i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }
}

int retira_duplicados(int *vetor, int tam){
    if(tam <= 1){
        return tam;
    }

    int k = 1;

    for(int i = 1; i < tam; i++){
        if(vetor[i] != vetor[i - 1]){
            vetor[k] = vetor[i];
            k++;
        }
    }

    return k;
}

int main(){
    int tam;

    printf("\nDigite o tamanho do vetor: ");
    scanf(" %d", &tam);

    int vetor[tam];

    preencher_vetor(vetor, tam);

    printf("\n====VETOR ATUAL:====\n");

    exibir_vetor(vetor, tam);

    int novo_tam = retira_duplicados(vetor, tam);

    printf("\n\n====NOVO VETOR:====\n");

    exibir_vetor(vetor, novo_tam);


}