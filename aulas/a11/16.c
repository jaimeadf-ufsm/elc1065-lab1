#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define SIZE 5

void ReadMatrix(int matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void PrintMatrix(int matrix[SIZE][SIZE])
{
    printf("\n");

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%4d", matrix[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

int main()
{
    int matrix[SIZE][SIZE];
    double result = 0;

    printf("Digite uma matriz de %dx%d:\n", SIZE, SIZE);
    ReadMatrix(matrix);
    PrintMatrix(matrix);

    for (int j = 0; j < SIZE; j++)
    {
        for (int i = SIZE - j; i < SIZE; i++)
        {
            if (matrix[i][j] % 2 == 1)
            {
                result += matrix[i][j] * matrix[i][j];
            }
        }
    }

    result = sqrt(result);

    printf("Resultado: %lf\n", result);

    return 0;
}