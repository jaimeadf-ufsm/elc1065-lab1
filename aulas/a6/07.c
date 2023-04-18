#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int multiplier, limit;
    int product;

    printf("Digite o numero da tabuada: ");
    scanf("%d", &multiplier);

    printf("Digite o limite: ");
    scanf("%d", &limit);

    for (int i = 1, product = 1; product <= limit; i++, product = multiplier * i)
    {
        printf("%d * %d = %d\n", multiplier, i, product);
    }

    return 0;
}
