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

int RemoveRepeated(char string[])
{
    int repeated = 0;

    for (int i = 0; i < strlen(string); i++)
    {
        int j = i + 1;

        while (j < strlen(string))
        {
            if (string[i] == string[j])
            {
                repeated++;
                RemoveIndex(string, j);
            }
            else
            {
                j++;
            }
        }
    }

    return repeated;
}

int main()
{
    char word[100];

    printf("Digite uma palavra: ");
    scanf("%s", word);

    int repeated = RemoveRepeated(word);

    printf("\n%s\n", word);
    printf("%d caracteres foram removidos\n", repeated);
    
    return 0;
}