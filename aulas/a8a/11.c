#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int x, y;

    printf("Digite os valores para x e y: ");
    scanf("%d %d", &x, &y);

    printf("   |");
    
    for (int column = x; column <= y; column++)
    {
        printf("%4d", column);
    }

    printf("\n");

    
    for (int column = x - 1; column <= y; column++)
    {
        printf("----", column);
    }

    printf("\n");

    for (int row = x; row <= y; row++)
    {
        printf("%2d |", row);

        for (int column = x; column <= y; column++)
        {
            printf("%4d", row * column);
        }

        printf("\n");
    }

    printf("\n");

    return 0;
}