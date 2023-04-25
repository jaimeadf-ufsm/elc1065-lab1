#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool IsPrime(int n)
{
    int divider = 2;

    while (divider < n)
    {
        if (n % divider == 0)
        {
            return false;
        }

        divider++;
    }

    return n > 1;
}

int main()
{
    int count = 0, number = 1;

    while (number > 0)
    {
        printf("Digite um numero inteiro: ");
        scanf("%d", &number);

        if (IsPrime(number))
        {
            count++;
        }
    }

    printf("Voce digitou %d numeros primos\n", count);
    
    return 0;
}