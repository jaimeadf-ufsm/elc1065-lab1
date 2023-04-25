#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    const double CHICO_GROWTH_RATE = 0.02;
    const double JUCA_GROWTH_RATE = 0.03;

    double chico_height = 1.5;
    double juca_height = 1.1;

    int years = 0;

    while (chico_height > juca_height)
    {
        years++;

        chico_height += CHICO_GROWTH_RATE;
        juca_height += JUCA_GROWTH_RATE;
    }

    printf("Sao necessarios %d anos para Juca ser maior que Chico.\n", years);
    printf("Altura Chico: %.2lfm\n", chico_height);
    printf("Altura Juca: %.2lfm\n", juca_height);

    return 0;
}