#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void check_for_collision()
{
    int aX0, aY0, aX1, aY1;
    int bX0, bY0, bX1, bY1;

    printf("Digite as coordenadas do primeiro retangulo: ");
    scanf("%d %d %d %d", &aX0, &aY0, &aX1, &aY1);

    printf("Digite as coordenadas do segundo retangulo: ");
    scanf("%d %d %d %d", &bX0, &bY0, &bX1, &bY1);

    if (
        aX0 <= bX0 && aX1 >= bX0 && aY0 <= bY0 && aY1 >= bY0 ||
        aX0 <= bX1 && aX1 >= bX1 && aY0 <= bY1 && aY1 >= bY1
    )
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
    
}

int main()
{
    check_for_collision();
    return 0;
}
