#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define SIZE 10

void ReadVector(double *vector, int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%lf", &vector[i]);
    }
}

void PrintVector(double *vector, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%.1lf\n", vector[i]);
    } 
}

int main()
{
    double vector_a[SIZE];
    double vector_b[SIZE];

    printf("Digite %d numeros para o vetor A:\n", SIZE);
    ReadVector(vector_a, SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        if (i % 2 == 0)
        {
            vector_b[i] = vector_a[i] * 3; 
        }
        else
        {
            vector_b[i] = vector_a[i] / 2; 
        }
    }

    printf("\nVetor B:\n");
    PrintVector(vector_b, SIZE);

    return 0;
}