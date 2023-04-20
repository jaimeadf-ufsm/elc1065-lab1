#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int n, j, m;

    printf("Quantos modulos congruentes voce deseja imprimir? ");
    scanf("%d", &n);

    printf("Digite m e j? ");
    scanf("%d %d", &m, &j);

    int remainder = j % m;

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", 4 * i + remainder);
    }
    

    return 0;
}
