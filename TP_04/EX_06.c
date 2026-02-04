#include <stdio.h>
#include <stdlib.h>

#define MES 2
#define SEM 4

void preencher_vendas(float vendas[MES][SEM])
{

    for (int i = 0; i < MES; i++)
    {
        for (int j = 0; j < SEM; j++)
        {
            printf("\nDigite os valores de vendas para o %dº Mes e %dª Semana: R$ ", i + 1, j + 1);
            scanf(" %f", &vendas[i][j]);
        }
    }
}

void somas(float vendas[MES][SEM])
{
    float semana;
    float soma_mes = 0;
    float soma_ano = 0;

    for (int i = 0; i < MES; i++)
    {

        for (int j = 0; j < SEM; j++)
        {
            semana = vendas[i][j];

            printf("\nVENDAS DO %dº MES E %dª SEMANA: R$ %.3f", i + 1, j + 1, semana);

            soma_mes += semana;
        }
        
        soma_ano += soma_mes;

        printf("\n\n>>>> TOTAL DO %dº MES: R$ %.3f", i + 1, soma_mes);

        soma_mes = 0;
    }

    printf("\n\n>>>> SOMA DO ANO: R$ %.3f", soma_ano);
}

int main()
{
    float vendas[MES][SEM];

    preencher_vendas(vendas);

    somas(vendas);

    return 0;
}