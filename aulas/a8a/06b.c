#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int number;
    int sum = 0, n = 0;

    printf("Digite alguns numeros (0 para parar): ");


    do {
        scanf("%d", &number);

        if (number != 0 && number % 2 == 0)
        {
            n++;
            sum += number;
        }

    } while (number != 0);

    double average = (double)sum / n;

    printf("Media dos numeros pares: %lf\n", average);
    
    return 0;
}