#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int PrintNaturals(int n, int increment)
{
    for (int natural = 0; natural <= n; natural += increment)
    {
        printf("%d\n", natural);
    }
}

int main()
{
    int n, increment;

    printf("Digite o limite superior do intervalo: ");
    scanf("%d", &n);

    printf("Digite o incremento: ");
    scanf("%d", &increment);

    PrintNaturals(n, increment);

    return 0;
}
