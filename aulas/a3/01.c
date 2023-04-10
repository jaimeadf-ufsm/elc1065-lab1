#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    const int count = 2;

    float gradeSum = 0;
    float weightSum = 0;

    for (int i = 0; i < count; i++)
    {
        float grade;
        float weight;

        printf("Digite a nota %d e seu peso: ", i);
        scanf("%f %f", &grade, &weight);

        gradeSum += grade;
        weightSum += weight;
    }

    float average = gradeSum / weightSum;

    printf("Media: %f\n", average);

    return 0;
}