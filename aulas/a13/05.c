#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

void Invert(char string[])
{
    int a = 0;
    int b = strlen(string) - 1;

    while (a < b)
    {
        char temp = string[a];

        string[a] = string[b];
        string[b] = temp;

        a++;
        b--;
    }
}

int main()
{
    char word[100];

    printf("Digite uma palavra: ");
    scanf("%s", word);

    Invert(word);

    printf("\n%s\n", word);

    return 0;
}