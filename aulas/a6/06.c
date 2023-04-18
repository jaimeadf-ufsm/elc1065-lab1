#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int n;
    int a = 0, b = 1;

    printf("Digite quantos termos voce quer imprimir: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a);
        a = a + b;
        b = a - b;
    }    

    printf("\n");

    return 0;
}
