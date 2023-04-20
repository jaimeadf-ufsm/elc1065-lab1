#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int sum = 0;

    for (int n = 101; n < 200; n++)
    {
        if (n % 13 != 0)
        {
            printf("%d\n", n);
            sum += n;
        }
    }

    printf("Soma: %d\n", sum);

    return 0;
}
