#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

double ConvertCelsiusToFahrenheit(double celsius)
{
    return celsius * 9.0 / 5.0 + 32.0;    
}

int main()
{
    double a, b;
    double control;

    printf("Digite o intervalo: ");
    scanf("%lf %lf", &a, &b);

    printf("Digite o incremento/decremento: ");
    scanf("%lf", &control);

    control = abs(control);
    control = b > a ? control : -control;

    for (double celsius = a; b > a ? celsius <= b : celsius >= b; celsius += control)
    {
        printf("%lf C = %lf F\n", celsius, ConvertCelsiusToFahrenheit(celsius));
    } 
    

    

    return 0;
}
