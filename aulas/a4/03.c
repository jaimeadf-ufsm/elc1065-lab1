#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    float num;

    printf("Digite um numero: ");
    scanf("%f", &num);

    if (num > 0)
    {
        printf("inverso: %f\n", 1 / num);
    }
    else
    {
        printf("valor absoluto: %f\n", num);
    }

    return 0;
}