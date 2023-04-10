#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int a, b;

    printf("Digite dois valores para A e B: ");
    scanf("%d %d", &a, &b);

    printf("A = %d\n", a);
    printf("B = %d\n", b);

    int temp = a;
    a = b;
    b = temp;

    printf("A = %d\n", a);
    printf("B = %d\n", b);

    return 0;
}