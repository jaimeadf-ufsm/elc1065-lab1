#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

void Duplicate(char string[])
{
    int final_length = strlen(string) * 2;

    for (int i = 0; i < final_length; i += 2)
    {
        for (int j = strlen(string); j >= i; j--)
            string[j + 1] = string[j];
    }
}

int main()
{
    char word[100];

    printf("Digite uma palavra: ");
    scanf("%s", word);

    Duplicate(word);

    printf("\n%s\n", word);

    return 0;
}