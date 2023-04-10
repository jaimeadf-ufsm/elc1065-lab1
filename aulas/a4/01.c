#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int a, b;
    int dividend, divisor;

    printf("Digite um inteiro para e A e para B: ");
    scanf("%d %d", &a, &b);

    if (a % b == 0 || b % a == 0)
    {
        printf("sao multiplos\n");
    }
    else
    {
        printf("nao sao multiplos\n");
    }

    return 0;
}