#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define LINES 2
#define COLUMNS 3

int main()
{
    int matrix[LINES][COLUMNS];

    printf("Digite uma matrix de %dx%d: \n", LINES, COLUMNS);

    for (int i = 0; i < LINES; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int j = 0; j < COLUMNS; j++)
    {
        for (int i = 0; i < LINES; i++)
        {
            printf("%4d", matrix[i][j]);
        }

        printf("\n");
    }
    

    return 0;
}