#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    double speedMPerS;
    printf("Digite a velocidade em m/s: ");
    scanf("%lf", &speedMPerS);
    printf("A velocidade em km/h eh %lf\n", speedMPerS * 3.6);

    return 0;
}