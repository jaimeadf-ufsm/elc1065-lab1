#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void Floyd(int n)
{
    int counter = 1;

    for (int line = 0; line < n; line++)
    {
        for (int column = 0; column <= line; column++)
        {
            printf("%-3d", counter);
            counter++;
        }

        printf("\n");
    }
}

int main()
{
    int n;

    printf("Digite o numero de linhas: ");
    scanf("%d", &n);

    Floyd(n);

    return 0;
}
