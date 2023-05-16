#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define SIZE 4

void PrintVector(double *numbers)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%.2lf ", numbers[i]);
    }

    printf("\n");
}

int main()
{
    double numbers[SIZE];

    printf("Digite 10 numeros reais: ");
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%lf", &numbers[i]);
    }

    printf("\n");

    PrintVector(numbers);

    for (int i = 0; i < SIZE; i++)
    {
        if (numbers[i] == 0)
        {
            numbers[i] = -99;
        }
    }

    PrintVector(numbers);

    return 0;
}