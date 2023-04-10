#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    char name[64];
    int age;

    printf("Digite seu primeiro nome e sua idade: ");
    scanf("%s %d", name, &age);

    printf("Seu nome eh %s e voc� tem %d anos\n", name, age);

    return 0;
}