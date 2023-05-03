#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int number;
    int sum = 0, n = 0;

    printf("Digite alguns numeros (0 para parar): ");

    scanf("%d", &number);

    while (number != 0)
    {
        if (number % 2 == 0)
        {
            n++;
            sum += number;
        }

        scanf("%d", &number);
    }

    double average = (double)sum / n;

    printf("Media dos numeros pares: %lf\n", average);

    return 0;
}