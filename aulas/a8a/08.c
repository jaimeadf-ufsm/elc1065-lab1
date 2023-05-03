#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int SumOfDivisors(int n)
{
    int sum = 0;

    for (int divisor = 1; divisor <= n / 2; divisor++)
    {
        if (n % divisor == 0)
        {
            sum += divisor;
        }
    }

    return sum;
}

int main()
{
    for (int a = 1 + 1; a < 100000; a++)
    {
        int b = SumOfDivisors(a);

        if (b > a && a == SumOfDivisors(b))
        {
            printf("%d e %d\n", a, b);
        }
    } 

    return 0;
}