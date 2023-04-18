#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool IsPrime(int n)
{
    for (int divider = 2; divider < n; divider++)
    {
        if (n % divider == 0)
        {
            return false;
        }
    }

    return true;
}

void PrintDividers(int n)
{
    for (int divider = 1; divider <= n; divider++)
    {
        if (n % divider == 0)
        {
            printf("%d\n", divider);
        }
    }
}

int main()
{
    int n;

    printf("Digite um valor inteiro: ");
    scanf("%d", &n);

    if (IsPrime(n))
    {
        printf("%d eh um numero primo.\n", n);
    }
    else
    {
        printf("Divisores:\n");
        PrintDividers(n);
    }

    return 0;
}
