#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define SIZE 10

void ReadVector(int *vector, int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &vector[i]);
    }
}

int main()
{
    int vector[SIZE];

    printf("Digite %d elementos:\n", SIZE);
    ReadVector(vector, SIZE);

    int bigger = vector[0];
    int smaller = vector[0];

    double average = 0;
    int even_count = 0;

    for (int i = 0; i < SIZE; i++)
    {
        if (vector[i] > bigger)
        {
            bigger = vector[i];
        }
        else if (vector[i] < smaller)
        {
            smaller = vector[i];
        }

        average += vector[i];

        if (vector[i] % 2 == 0)
        {
            even_count++;
        }
    }

    average /= SIZE;

    printf("Maior: %d\n", bigger);
    printf("Menor: %d\n", smaller);
    printf("Media: %.2lf\n", average);
    printf("Pares: %.2lf%%\n", (double)even_count / SIZE * 100);

    return 0;
}