#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    double a, b, c;

    printf("Digite os termos da equacao de segundo grau (ax^2 + bx + c): ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double delta = b * b - 4 * a * c;

    if (delta > 0)
    {
        double delta_squared = sqrt(delta);

        double x1 = (-b + delta_squared) / (2 * a);
        double x2 = (-b - delta_squared) / (2 * a);

        printf("x1 = %lf; x2 = %lf\n", x1, x2);
    }
    else if (delta == 0)
    {
        double x = -b / (2 * a);

        printf("x = %lf\n", x);
    }
    else
    {
        printf("A equacao nao possui raizes reais\n");
    }

    return 0;
}