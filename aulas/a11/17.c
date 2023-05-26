#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define SIZE 3

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
    int matrix_a[SIZE][SIZE];
    int matrix_b[SIZE][SIZE];

    printf("Digite uma matriz de %dx%d:\n", SIZE, SIZE);
    ReadMatrix(matrix_a);

    PrintMatrix(matrix_a);

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrix_b[j][SIZE - i - 1] = matrix_a[i][j];
        }
    }

    PrintMatrix(matrix_b);

    return 0;
}