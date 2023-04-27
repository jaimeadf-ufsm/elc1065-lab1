#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int number;
    int sum = 0, n = 0;

    do
    {
        printf("Digite um numero: ");
        scanf("%d", &number);

        if (number != 0 && number % 2 == 0)
        {
            sum += number;
            n++;
        }
    } while (number != 0);

    double average = (double)sum / n;

    printf("Media dos numeros pares: %lf\n", average);
    
    return 0;
}