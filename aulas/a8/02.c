#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int count = 0;
    double number, product = 1;

    do
    {
        printf("Digite um numero (-1 para sair): ");
        scanf("%lf", &number);

        if (number > 0)
        {
            count++;
            product *= number;
        }
    } while (number > 0);

    printf("Produto: %lf (%d valores)\n", product, count);

    return 0;
}