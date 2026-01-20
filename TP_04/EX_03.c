#include <stdio.h>
#include <stdlib.h>

#define QTD 5

#define preco_pes 10.0
#define preco_maos 15.0
#define preco_podologia 30.0

#define RED   "\033[31m"
#define RESET "\033[0m"

struct manicures{
    int qt_pes;
    int qt_maos;
    int qt_podologia;
};

typedef struct manicures manicures;

void cadastro(manicures lista[QTD]){
    for(int i = 0; i < QTD; i++){
        printf("\nDIGITE AS INFORMACOES PARA A " RED "%dª" RESET " MANICULE\n", i+1);

        printf("\nDigite a quantidade de " RED "pes" RESET " feitos: ");
        scanf(" %d", &lista[i].qt_pes);

        printf("\nDigite a quantidade de " RED "maos" RESET " feitas: ");
        scanf(" %d", &lista[i].qt_maos);

        printf("\nDigite a quantidade de " RED "podologias" RESET " feitas: ");
        scanf(" %d", &lista[i].qt_podologia);
    }
}

int main(){

    manicures lista[QTD];

    cadastro(lista);

    printf("\n======VALORES A RECEBER======\n");

    for(int i = 0; i < QTD; i++){

        float total_pes = lista[i].qt_pes * preco_pes;
        float total_maos = lista[i].qt_maos * preco_maos;
        float total_podologia = lista[i].qt_podologia * preco_podologia;

        float soma = total_pes + total_maos + total_podologia;

        printf(RED "\n%dª" RESET " MANICURE:\n", i+1);

        printf("\nPES: %d X R$ 10,00 = " RED "R$ %.2f" RESET, lista[i].qt_pes, total_pes);

        printf("\nMAOS: %d X R$ 15,00 = " RED "R$ %.2f" RESET, lista[i].qt_maos, total_maos);

        printf("\nPODOLOGIA: %d X R$ 30,00 = " RED "R$ %.2f\n" RESET, lista[i].qt_podologia, total_podologia);

        printf("\nVALOR A RECEBER (50%%): " RED "R$ %.2f\n" RESET, soma * 0.5);
    }

    return 0;

}