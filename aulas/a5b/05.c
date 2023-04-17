#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void display_result(double area)
{
    printf("\n%lf u.a.\n", area);
}

void square_area()
{
    double side;

    printf("Digite o lado do quadrado: ");
    scanf("%lf", &side);

    display_result(side * side);
}

void rectangle_area()
{
    double width, height;

    printf("Digite a largura e a altura do retangulo: ");
    scanf("%lf %lf", &width, &height);

    display_result(width * height);
}

void triangle_area()
{
    double base, height;

    printf("Digite a base e a altura do triangulo: ");
    scanf("%lf %lf", &base, &height);

    display_result(base * height / 2);
}

void trapezoid_area()
{
    double base_0, base_1, height;

    printf("Digite a base menor, a base maior e a altura do trapezio: ");
    scanf("%lf %lf %lf", &base_0, &base_1, &height);

    display_result((base_0 + base_1) * height / 2);
}


int main()
{
    printf("Figuras suportas: \n");
    printf("q) Quadrado\n");
    printf("r) Retangulo\n");
    printf("t) Triangulo\n");
    printf("p) Trapezio\n");
    printf("\n");

    char shape;

    printf("Qual figura voce deseja calcular a area? ");
    scanf(" %c", &shape);

    switch (shape)
    {
        case 'q':
            square_area();
            break;
        case 'r':
            rectangle_area();
            break;
        case 't':
            triangle_area();
            break;
        case 'p':
            trapezoid_area();
            break;
        default:
            printf("Figura geometrica nao suportada.\n");    
    }

    
    return 0;
}
