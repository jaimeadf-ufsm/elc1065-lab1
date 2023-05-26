#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

void Invert(unsigned int *inverted)
{
    int n = *inverted;

    *inverted = 0;

    while (n > 0)
    {
        int digit = n % 10;

        n /= 10;
        *inverted += digit;

        if (n != 0)
            *inverted *= 10;
    }
}

int main()
{
    int n;

    printf("Digite N: ");
    scanf("%d", &n);

    Invert(&n);

    printf("Invertido: %d\n", n);

    return 0;
}