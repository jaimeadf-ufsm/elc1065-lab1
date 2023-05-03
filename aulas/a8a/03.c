#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool IsThreeDigitNumber(int n)
{
    return n / 100 > 0 & n / 1000 == 0;
}

void CheckHundredDigit(int n)
{
    int digit = n / 100;

    if (digit % 2 == 0)
    {
        printf("%d eh par\n", digit);
    }
    else
    {
        printf("%d eh impar\n", digit);
    }
}

int main()
{
    int n;

    do {
        scanf("%d", &n);

        if (IsThreeDigitNumber(n))
        {
            CheckHundredDigit(n);
        }
    } while (IsThreeDigitNumber(n));

    return 0;
}