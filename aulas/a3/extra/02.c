#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int a, b, c;
    float d;

    a = 5;
    b = 2;

    c = a / b;
    printf("c = %d\n", c);

    d = (float)a / b;
    printf("d = %lf\n", d);

    return 0;
}