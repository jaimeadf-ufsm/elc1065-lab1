#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int sum = 0, number = 0;

    do
    {
        sum += number;

        printf("Digite um valor inteiro e positivo (ou -1 para parar): ");
        scanf("%d", &number);
    } while (number >= 0);

    printf("Soma: %d\n", sum);

    return 0;
}