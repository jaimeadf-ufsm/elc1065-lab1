#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int ana;
    int bob;
    int caren;

    printf("Digite as escolhas de dois em um de Ana, Bob e Caren, respectivamente: ");
    scanf("%d %d %d", &ana, &bob, &caren);

    printf("Entrada %d %d %d; Saida ", ana, bob, caren);

    if (ana != bob && ana != caren)
    {
        printf("Ana");
    }
    else if (bob != ana && bob != caren)
    {
        printf("Bob");
    }
    else if (caren != ana && caren != bob)
    {
        printf("Caren");
    }
    else
    {
        printf("*");
    }

    printf(".\n");

    return 0;
}