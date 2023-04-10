#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    float a, b, c;

    printf("Digite as medidas dos tres lados do triangulo: ");
    scanf("%f %f %f", &a, &b, &c);

    if (
        a < (b + c) && a > abs(b - c) &&
        b < (a + c) && b > abs(a - c) &&
        c < (a + b) && c > abs(a - b))
    {
        float s = (a + b + c) / 2;
        float area = sqrt(s * (s - a) * (s - b) * (s - c));

        printf("A area do triangulo eh %f u.a.\n", area);
    }
    else
    {
        printf("Os lados %f, %f e %f nao formam um triangulo\n", a, b, c);
    }

    return 0;
}