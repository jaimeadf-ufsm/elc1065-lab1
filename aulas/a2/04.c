#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    char name[64];

    printf("Digite uma bela palavra: ");
    scanf("%s", name);

    printf("%s\n", name);
    printf("\"%s\"\n", name);

    return 0;
}