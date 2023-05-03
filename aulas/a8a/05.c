#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int n;
    int position = 0;

    printf("Digite uma sequencia de numeros (0 para finalizar): ");

    do {
        scanf("%d", &n);

        if (n != 0)
        {
            position++;

            if (n % position == 0)
            {
                printf("%d\n", n);
            }
        }
    } while (n != 0);

    return 0;
}