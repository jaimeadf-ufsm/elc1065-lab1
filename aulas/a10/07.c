#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define LINES 4
#define COLUMNS 4

void ReadMatrix(int matrix[LINES][COLUMNS])
{
    printf("Digite uma matrix de %dx%d: \n", LINES, COLUMNS);

    for (int i = 0; i < LINES; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    } 
}

void PrintMatrix(int matrix[LINES][COLUMNS])
{
    for (int i = 0; i < LINES; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            printf("%4d", matrix[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

int main()
{
    int a[LINES][COLUMNS];
    int b[LINES][COLUMNS];

    int c[LINES][COLUMNS];

    ReadMatrix(a);
    ReadMatrix(b);

    for (int i = 0; i < LINES; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            int element_a = a[i][j];
            int element_b = b[i][j];

            c[i][j] = element_a > element_b ? element_a : element_b;
        }
    }

    PrintMatrix(c);

    return 0;
}