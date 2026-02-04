#include <stdio.h>
#include <stdlib.h>


void preencher_vetor(int *binarios, int tam){
    for(int i = 0; i < tam; i++){
        printf("\nDigite o %dº Numero: ", i+1);
        scanf(" %d", &binarios[i]);
    }
}

int converter_binario(int *binarios, int tam){
    int valor_decimal = 0;

    for(int i = 0; i < tam; i++){
        int bit = binarios[i];

        if(bit == 0 || bit == 1){
            valor_decimal = valor_decimal * 2 + bit;
        } else {
            return -1;
        }
    }
    return valor_decimal;
}


int main(){

    int tam;

    printf("\nDigite quantos digitos seu numero binario tem: ");
    scanf(" %d", &tam);

   int vetor_binarios[tam];

   preencher_vetor(vetor_binarios, tam);

   int valor_decimal = converter_binario(vetor_binarios, tam);
   
   if (valor_decimal != -1){
        printf("\nValor em Decimal: %d\n", valor_decimal);
   } else {
        printf("\nERRO! Bits diferentes de 0 e 1!");
   }

   return 0;
}