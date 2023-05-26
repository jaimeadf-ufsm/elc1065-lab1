#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

void CountDivisors(int *number)
{
    int divisors = 0;

    for (int i = 1; i <= *number; i++)
    {
        if (*number % i == 0)
            divisors++;
    }

    *number = divisors;
}

int main()
{
    int n;

    printf("Digite N: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int number;

        printf("Digite um numero: ");
        scanf("%d", &number);

        CountDivisors(&number);

        printf("Existem %d divisores\n", number);
    }

    return 0;
}