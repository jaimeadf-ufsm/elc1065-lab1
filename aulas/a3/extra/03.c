#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    double base, height;

    printf("Digite a base e a altura do triangulo: ");
    scanf("%lf %lf", &base, &height);

    double area = base * height / 2;
    printf("A area do triangulo eh %lf\n", area);

    return 0;
}