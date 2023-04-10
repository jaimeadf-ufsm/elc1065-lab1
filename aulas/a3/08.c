#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    float r, a1;

    printf("Digite a razao e o primeiro termo da PA: ");
    scanf("%f %f", &r, &a1);

    float a10 = a1 + r * (10 - 1);

    printf("O decimo termo da PA: %f\n", a10);

    return 0;
}