#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int points_a;
    int points_b;
    int points_c;

    printf("Digite a pontuacao dos tres competidores: ");
    scanf("%d %d %d", &points_a, &points_b, &points_c);

    int points_second = 0;

    if (points_a > points_b && points_a < points_c || points_a < points_c && points_a > points_b) {
        points_second = points_a;
    }
    else if (points_b > points_a && points_b < points_c || points_b > points_c && points_b < points_a)
    {
        points_second = points_b;
    }
    else
    {
        points_second = points_c;
    }

    printf("A pontuacao do vice campeao eh: %d\n", points_second);

    return 0;
}