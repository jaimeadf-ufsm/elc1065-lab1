#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    double total_area, built_area;

    printf("Digite a area total do terreno e a area da casa em m2: ");
    scanf("%lf %lf", &total_area, &built_area);

    double free_area = total_area - built_area;
    double free_area_percentage = free_area / total_area * 100;

    printf("Area livre em m2: %lf (%lf\%)", free_area, free_area_percentage);

    return 0;
}