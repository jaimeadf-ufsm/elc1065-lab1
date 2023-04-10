#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    double value_per_hour;
    int hours_per_month;

    printf("Digite o valor da hora de trabalho e a quantidade de horas por mes de um funcionario: ");
    scanf("%lf %d", &value_per_hour, &hours_per_month);

    double gross_salary = value_per_hour * hours_per_month;

    double ir = gross_salary * 0.11;
    double inss = gross_salary * 0.08;
    double sindical_contribution = gross_salary * 0.05;
    double liquid_salary = gross_salary - ir - inss - sindical_contribution;

    printf("Salario Bruto: %lf\n", gross_salary);
    printf("Salario Liquido: %lf\n", liquid_salary);
    printf("Imposto de Renda: %lf\n", ir);
    printf("INSS: %lf\n", inss);
    printf("Contribuicao Sindical: %lf\n", sindical_contribution);

    return 0;
}