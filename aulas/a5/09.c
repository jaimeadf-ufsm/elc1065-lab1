#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int x, y, z;

    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &x, &y);

    z = x < y ? x : y;

    printf("O menor valor eh %d\n", z);

    return 0;
}
