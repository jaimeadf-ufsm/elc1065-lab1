#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    float celsius;

    printf("Digite uma temperature em graus celsius: ");
    scanf("%f", &celsius);

    float fahrenheit = celsius * 9 / 5 + 32;

    printf("Temperatura em graus fahrenheit: %f\n", fahrenheit);

    return 0;
}