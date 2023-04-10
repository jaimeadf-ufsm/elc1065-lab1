#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int number;

    printf("Digite um numero de tres algarismos: ");
    scanf("%d", &number);

    printf("O algarismo das dezenas eh: %d\n", (number % 100 - number % 10) / 10);

    return 0;
}