#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool IsPrime(int n)
{
    for (int divisor = 2; divisor < n; divisor++)
    {
        if (n % divisor == 0)
        {
            return false;
        }
    }

    return n > 1;
}

void PrintArrangements(int n)
{
    for (int a = 2; a <= n; a++)
    {
        if (IsPrime(a))
        {
            for (int b = 2; b <= n; b++)
            {
                if (IsPrime(b))
                {
                    if (a + b == n)
                    {
                        printf("%d + %d = %d\n", a, b, n);
                    }
                }
            }
        }
    }
}

int main()
{
    int n;

    printf("Digite numeros pares para obter seus arranjos de primos: ");

    do
    {
        scanf("%d", &n);

        if (n % 2 == 0)
        {
            PrintArrangements(n);
        }
    } while (n % 2 == 0);
    
    
    return 0;
}