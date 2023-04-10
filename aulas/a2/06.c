#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int x;
    float y;
    double z;

    printf("Digite um valor para X, Y e Z: ");
    scanf("%d %f %lf", &x, &y, &z);

    printf("X = %d, Y = %.3f, Z = %.4lf\n", x, y, z);

    return 0;
}