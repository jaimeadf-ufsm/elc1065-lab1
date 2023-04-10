#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    printf("Os alunos sao %d.\n", 350);
    printf("Os alunos sao %2d.\n", 350);
    printf("Os alunos sao %4d.\n", 350);
    printf("Os alunos sao %6d.\n", 350);
    printf("Os alunos sao %02d.\n", 350);
    printf("Os alunos sao %04d.\n", 350);
    printf("Os alunos sao %06d.\n", 350);
    printf("Os alunos sao %10.02d.\n", 350);
    printf("Os alunos sao %10.04d.\n", 350);
    printf("Os alunos sao %10.06d.\n", 350);
    printf("Os alunos sao %d.\n", 350);

    return 0;
}