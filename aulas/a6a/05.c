#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void PromptAndSum()
{
    int sum = 0;

    for (int i = 1; i <= 20; i++)
    {
        int number;

        printf("Digite o numero %d: ", i);
        scanf("%d", &number);

        if (number * number < 225)
        {
            sum += number;
        }
    }

    printf("Soma: %d\n", sum);
}

int main()
{
    PromptAndSum();
    return 0;
}
