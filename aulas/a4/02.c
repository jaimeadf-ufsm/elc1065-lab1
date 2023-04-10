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
        printf("%f eh positivo\n", num);
    }
    else if (num < 0)
    {
        printf("%f eh negativo\n", num);
    }
    else
    {
        printf("%f eh nulo\n", num);
    }

    return 0;
}