#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int start, end;
    int sum;

    printf("Digite o inicio do intervalo: ");
    scanf("%d", &start);

    printf("Digite o fim do intervalo: ");
    scanf("%d", &end);

    for (int i = start % 2 == 0 ? start + 1 : start; i <= end; i += 2)
    {
        printf("%d ", i);
    }

    printf("\n");

    return 0;
}

