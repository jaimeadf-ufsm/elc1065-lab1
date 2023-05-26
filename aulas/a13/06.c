#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

void RemoveIndex(char string[], int index)
{
    int length = strlen(string);

    for (int i = index; i < length; i++)
    {
        string[i] = string[i + 1];
    }
}

void RemoveRepeated(char string[])
{
    for (int i = 0; i < strlen(string); i++)
    {
        int j = i + 1;

        while (j < strlen(string))
        {
            if (string[i] == string[j])
                RemoveIndex(string, j);
            else
                j++;
        }
    }
}

int main()
{
    char word[100];

    printf("Digite uma palavra: ");
    scanf("%s", &word);

    RemoveRepeated(word);
    
    printf("\n%s\n", word);

    return 0;
}