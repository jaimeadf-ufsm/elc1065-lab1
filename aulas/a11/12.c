#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define MATRIX_SIZE 4
#define FILTER_SIZE ((MATRIX_SIZE - 1) * MATRIX_SIZE) / 2

void ReadMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void PrintVector(int *vector, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", vector[i]);
    } 
}

bool Contains(int *vector, int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (vector[i] == element)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int matrix[MATRIX_SIZE][MATRIX_SIZE];

    int diff[2 * FILTER_SIZE];

    int a[FILTER_SIZE];
    int b[FILTER_SIZE];

    int n_diff = 0;

    int n_a = 0;
    int n_b = 0;

    printf("Digite uma matriz de %dx%d: ", MATRIX_SIZE, MATRIX_SIZE);
    ReadMatrix(matrix);

    for (int j = 0; j < MATRIX_SIZE; j++)
    {
        for (int i = MATRIX_SIZE - j; i < MATRIX_SIZE; i++)
        {
            a[n_a++] = matrix[i][j];
        }
    }

    for (int j = 0; j < MATRIX_SIZE; j++)
    {
        for (int i = 0; i < j; i++)
        {
            b[n_b++] = matrix[i][j];
        }
    }

    for (int i = 0; i < n_a; i++)
    {
        if (!Contains(b, n_b, a[i]))
        {
            diff[n_diff++] = a[i];
        }
    }
    
    printf("\nDiferencas:\n");
    for (int i = 0; i < n_diff; i++)
    {
        printf("%d\n", diff[i]);
    }

    return 0;
}