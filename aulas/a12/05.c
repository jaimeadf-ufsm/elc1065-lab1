#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

int main()
{
    int k = 1;

    char string[100];

    printf("Digite o texto para criptografar: ");
    gets(string);

    for (int i = 0; string[i] != '\0'; i++)
    {
        string[i] += k;
    }

    printf("\n%s\n", string);

    return 0;
}