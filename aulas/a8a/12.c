#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int tower_y, tower_x;

    printf("Movimentos de uma Torre no xadrez!\n");
    printf("Digite a linha e a coluna em que sua Torre se encontra: ");
    scanf("%d %d", &tower_y, &tower_x);

    printf("   ");

    for (int x = 1; x <= 8; x++)
    {
        printf("%3d", x);
    }

    printf("\n");


    for (int x = 0; x <= 8; x++)
    {
        printf("---");
    }

    printf("\n");

    for (int y = 1; y <= 8; y++)
    {
        printf("%d |", y);

        for (int x = 1; x <= 8; x++)
        {
            if (y == tower_y || x == tower_x)
            {
                printf("%3c", 'x');
            }
            else
            {
                printf("%3c", '-');
            }
        }
  
        printf("\n");
    }
    
    return 0;
}