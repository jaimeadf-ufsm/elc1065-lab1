#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define SIZE 4

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

int main()
{
    int matrix[SIZE][SIZE];
    int sum = 0;

    printf("Digite uma matriz de %dx%d:\n", SIZE, SIZE);
    ReadMatrix(matrix);

    for (int j = 0; j < SIZE; j++)
    {
        for (int i = 0; i < j; i++)
        {
            sum += matrix[i][j];
        }
    }

    printf("\nSoma: %d\n", sum);

    return 0;
}