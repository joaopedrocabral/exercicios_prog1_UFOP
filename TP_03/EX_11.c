#include <stdio.h>
#include <stdlib.h>

int fatorial(int n)
{
    int fat = 1;
    for (int i = n; i >= 1; i--)
    {
        fat *= i;
    }
    return fat;
}

int arrajo(int p, int n)
{
    if (p > n || p < 0 || n < 0)
    {
        return -1;
    }
    return fatorial(n) / fatorial(n - p);
}

int main()
{
    int p, n;

    printf("\nDigite P e N: ");
    scanf("%d %d", &p, &n);
    
    int res = arrajo(p, n);

    if (res != -1)
    {
        printf("\nA(%d,%d) = %d", n, p, res);
    }
    else
    {
        printf("\nHouve um erro com os numeros, tente novamente.");
    }

    return 0;
}