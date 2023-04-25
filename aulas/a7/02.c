#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int Sum(int m, int n)
{
    int total = 0;
    int i = 0;

    while (i < n)
    {
        total = total + m + i;
        i++;
    }

    return total;
}

int main()
{
    int m = 1, n = 1;

    while (m > 0 && n > 0)
    {
        printf("Digite os valores para m e n: ");
        scanf("%d %d", &m, &n);

        printf("Soma dos %d inteiros consecutivos a partir de %d: %d\n", n, m, Sum(m, n));
    }
    
    return 0;
}