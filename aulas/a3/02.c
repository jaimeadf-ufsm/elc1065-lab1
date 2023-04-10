#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int x, y;

    printf("Digite um valor para X e outro para Y: ");
    scanf("%d %d", &x, &y);

    printf("X + 1 = %d, Y - 1 = %d\n", ++x, --y);

    return 0;
}