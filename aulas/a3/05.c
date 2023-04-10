#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    const float lifeExpectancyAge = 76.6;
    int age;

    printf("Digite sua idade: ");
    scanf("%d", &age);

    printf("Voce possui %f dias restantes de vida\n", (lifeExpectancyAge - age) * 365);

    return 0;
}