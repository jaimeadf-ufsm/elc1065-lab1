#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define LINES 2
#define COLUMNS 2

int main()
{
    int matrix[LINES][COLUMNS];

    for (int i = 0; i < LINES; i++)
    {
        printf("Digite %d valores para a %d linha: ", COLUMNS, i);

        for (int j = 0; j < COLUMNS; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < LINES; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (j + 1 == COLUMNS - i)
            {
                printf("    ");
            }
            else
            {
                printf("%4d", matrix[i][j]);
            }
        }

        printf("\n");
    }
    

    return 0;
}