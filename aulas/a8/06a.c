#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int number;
    int sum = 0, n = 0;

    printf("Digite um numero: ");
    scanf("%d", &number);

    while (number != 0)
    {
        if (number % 2 == 0)
        {
            sum += number;
            n++;
        }
        
        printf("Digite um numero: ");
        scanf("%d", &number);
    }

    double average = (double)sum / n;

    printf("Media dos numeros pares: %lf\n", average);
    
    return 0;
}