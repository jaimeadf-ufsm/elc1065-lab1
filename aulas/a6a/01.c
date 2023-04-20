#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int PromptSum(int n)
{
    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        int number;
    
        printf("Digite o numero %d: ", i);
        scanf("%d", &number);

        sum += number;
    }

    return sum;
}

int main()
{
    int n;

    printf("Digite quantos numeros voce deseja somar: ");
    scanf("%d", &n);

    printf("Soma: %d\n", PromptSum(n));
    
    return 0;
}
