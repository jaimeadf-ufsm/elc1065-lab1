#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int numerator, denominator;
    double sum;

    printf("S = ");

    for (numerator = 1, denominator = 1; numerator <= 50; numerator += 2, denominator++)
    {
        if (numerator != 1)
        {
            printf(" + ");
        }

        printf("(%d / %d)", numerator, denominator);

        sum += (double)numerator / denominator;
    }

    printf(" = %lf\n", sum);

    return 0;
}
