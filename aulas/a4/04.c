#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    if (num % 3 == 0 && num % 7 == 0)
    {
        printf("%d eh divisivel por 3 e por 7 simultaneamente\n", num);
    }
    else
    {
        printf("%d nao eh divisivel por 3 e por 7 simultaneamente\n", num);
    }

    return 0;
}