#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int LeastCommonMultiple(int a, int b)
{
    int multiple = 1;

    while (multiple % a != 0 || multiple % b != 0)
    {
        multiple++;
    }

    return multiple;
}

void PrintMultiples(int a, int b, int n)
{
    int lcm = LeastCommonMultiple(a, b);

    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", i * lcm);
    }
}

int main()
{
    int a, b, n;
    
    printf("Digite dois numeros: ");
    scanf("%d %d", &a, &b);

    printf("Quantos multiplos voce deseja imprimir? ");
    scanf("%d", &n);

    PrintMultiples(a, b, n);

    return 0;
}