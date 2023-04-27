#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int MDC(int a, int b)
{
    int divisor = 0;
    int max_divisor = 1;

    do
    {
        divisor++;

        if (a % divisor == 0 && b % divisor == 0)
        {
            max_divisor = divisor;
        }
    } while (divisor < a && divisor < b);
    
    return max_divisor;
}

int main()
{
    int a, b;

    printf("Digite dois valores para encontrar o M.D.C.: ");
    scanf("%d %d", &a, &b);

    printf("MDC(%d, %d): %d\n", a, b, MDC(a, b));
    
    return 0;
}