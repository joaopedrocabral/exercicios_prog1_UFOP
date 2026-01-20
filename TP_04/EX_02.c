#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QTD 3
#define RED   "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"


struct plantas{
    char nome [20];
    int es_ideal;
    int es_atual;
};

typedef struct plantas plantas;

void preencher_lista(plantas lista[QTD]){

    for(int i = 0; i < QTD; i++){
        printf("\nDIGITE AS INFORMACOES PARA A "RED"%dª PLANTA"RESET, i+1);

        printf("\nDigite o "GREEN"Nome da Planta: "RESET);
        scanf(" %s", lista[i].nome);

        printf("\nDigite o "GREEN"Estoque Ideal"RESET" para essa planta: ");
        scanf(" %d", &lista[i].es_ideal);

        printf("\nDigite o "GREEN"Estoque Atual"RESET" dessa planta: ");
        scanf(" %d", &lista[i].es_atual);
    }
}

void exibir_lista(plantas lista[QTD]){
    for(int i = 0; i < QTD; i++){
        if(lista[i].es_atual < lista[i].es_ideal){
            printf("\nPLANTA: "GREEN"%s"RESET, lista[i].nome);
            printf("\nQUANTIDADE: "GREEN"%d"RESET, lista[i].es_ideal - lista[i].es_atual);
        }
        printf("\n");
    }
}

int main(){
    plantas lista[QTD];

    preencher_lista(lista);

    printf("\n=======LISTA DE COMPRAS=======");

    exibir_lista(lista);

    return 0;
    

}