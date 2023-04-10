#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    double weight_a;
    double weight_b;
    double weight_c;
    double weight_d;

    printf("Digite os pesos das bolas A, B, C e D: ");
    scanf("%lf %lf %lf %lf", &weight_a, &weight_b, &weight_c, &weight_d);

    if (
        weight_a == weight_b + weight_c + weight_d &&
        weight_b + weight_c == weight_d &&
        weight_b == weight_c)
    {
        printf("O mobile esta completamente equilibrado.\n");
    }
    else
    {
        printf("O mobile NAO esta completamente equilibrado.\n");
    }

    return 0;
}