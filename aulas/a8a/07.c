#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int a, b;
    int quotient = 0;

    printf("Digite dois numeros para efetuar a divisao: ");
    scanf("%d %d", &a, &b);

    while (quotient + b <= a)
    {
        quotient += b;
    }

    int remainder = a - quotient;

    printf("Quociente: %d\n", quotient);
    printf("Resto: %d\n", remainder);
    
    return 0;
}