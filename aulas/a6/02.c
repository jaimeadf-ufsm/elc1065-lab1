#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int number, max;
    bool has_max = false;

    for (int i = 1; i <= 20; i++)
    {
        printf("Digite o numero %d: ", i);
        scanf("%d", &number);

        if (number > max || !has_max)
        {
            max = number;
            has_max = true;
        }
    }

    printf("O maior numero digitado foi %d\n", max);

    return 0;
}
