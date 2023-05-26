#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

bool IsPalindrome(char *string)
{
    int length = strlen(string);

    for (int i = 0; i < length / 2; i++)
    {
        if (string[i] != string[length - i - 1])
            return false;
    }

    return true;
}

int main()
{
    char string[100];

    printf("Digite um texto: ");
    scanf("%s", string);

    if (IsPalindrome(string))
    {
        printf("considera-se %s um palindromo.\n", string);
    }
    else
    {
        printf("NAO considera-se %s um palindromo.\n", string);
    }

    return 0;
}