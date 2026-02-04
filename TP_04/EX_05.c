#include <stdio.h>
#include <stdlib.h>

#define DEL 5
#define ALT 10

void preencher_alturas(int alturas[DEL][ALT])
{
    for (int i = 0; i < DEL; i++)
    {
        for (int j = 0; j < ALT; j++)
        {
            printf("\nDIGITE A ALTURA DO %dº JOGADOR DA %dª DELEGACAO (cm): ", j + 1, i + 1);
            scanf(" %d", &alturas[i][j]);
            printf("\n");
        }
    }
}

void maior_altura(int alturas[DEL][ALT])
{
    int maior_altura = 0;
    int altura_atual = 0;

    for (int i = 0; i < DEL; i++)
    {
        for (int j = 0; j < ALT; j++)
        {

            altura_atual = alturas[i][j];

            if (altura_atual > maior_altura)
            {
                maior_altura = altura_atual;
                altura_atual = 0;
            }
        }
        printf("\nMAIOR ALTURA DA DELEGACAO %d = %d\n", i + 1, maior_altura);
        maior_altura = 0;
    }
}

int main()
{
    int alturas[DEL][ALT]; //[Delegações][Altura]

    preencher_alturas(alturas);
    maior_altura(alturas);

    return 0;
}