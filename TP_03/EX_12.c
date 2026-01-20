#include <stdio.h>
#include <stdlib.h>

long long fatorial(int n)
{
    long long fat = 1;
    for (int i = n; i >= 1; i--)
    {
        fat *= i;
    }
    return fat;
}

long long combinacoes(int n, int p)
{
    if (p > n || p < 0 || n < 0)
    {
        return -1;
    }
    return (fatorial(n) / (fatorial(p) * fatorial(n - p)));
}

int main()
{
    int n, p;

    printf("\nDigite o valor para N e P: ");
    scanf("%d %d", &n, &p);

    long long res = combinacoes(n, p);

    if (res != -1)
    {
        printf("\nC(%d,%d) = %lld", n, p, res);
    }
    else
    {
        printf("\nHouve um erro com os numeros, tente novamente.");
    }
    return 0;
}