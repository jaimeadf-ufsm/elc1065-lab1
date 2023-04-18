#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int registration;
    float grade1, grade2, grade3, average;

    for (int i = 0; i < 10; i++)
    {
        printf("Digite a matricula do aluno: ");
        scanf("%d", &registration);

        printf("Digite as tres notas do semestre: ");    
        scanf("%f %f %f", &grade1, &grade2, &grade3);

        average = (grade1 * 4 + grade2 * 3 + grade3 *3) / 10;

        printf("%d (", registration);
        printf(average >= 7.0 ? "APROVADO" : "REPROVADO");
        printf(")\n");
        printf("(%f * 4 + %f * 3 + %f * 3) / 10 = %f\n\n", grade1, grade2, grade3, average);
    }

    return 0;
}
