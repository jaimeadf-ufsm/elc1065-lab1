#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int CalculateA(int n)
{
    int h = 0;
 
    printf("H =");
   
    for (int denominator = 1; denominator <= n; denominator++)
    {
        int fraction = 1 / denominator;

        printf(" ");

        if (denominator % 2 == 0)
        {
            printf("-");
            h -= fraction;
        }
        else
        {
            printf("+");
            h += fraction;    
        }

        printf(" (1/%d)", denominator, fraction);
    }

    printf("\n");

    return h;
}

double CalculateB(int n)
{
    double h = 0;
 
    printf("H =");
   
    for (int denominator = 1; denominator <= n; denominator++)
    {
        double fraction = 1.0 / denominator;

        printf(" ");

        if (denominator % 2 == 0)
        {
            printf("-");
            h -= fraction;
        }
        else
        {
            printf("+");
            h += fraction;    
        }

        printf(" (1/%d)", denominator);
    }

    printf("\n");

    return h;
}

int main()
{
    int n;

    printf("Digite o valor de N: ");
    scanf("%d", &n);

    printf("a) H = %d\n\n", CalculateA(n));
    printf("b) H = %lf\n\n", CalculateB(n));

    return 0;
}
