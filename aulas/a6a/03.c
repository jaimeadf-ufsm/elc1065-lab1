#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void PromptAndCalculate()
{
    int even = 0;
    int odd = 0;
    int sum = 0;

    for (int i = 1; i <= 200; i++)
    {
        int number;

        printf("Digite o numero %d: ", i);
        scanf("%d", &number);

        if (number % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }

        sum += number;
    }
    
    printf("Pares: %d\n", even);
    printf("Impares: %d\n", odd);
    printf("Soma: %d\n", sum);
}

int main()
{
    PromptAndCalculate();
    return 0;
}
