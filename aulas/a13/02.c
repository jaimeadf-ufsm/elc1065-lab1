#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

bool IsPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return n > 1;    
}

int F(int n, int *p1, int *p2)
{
    *p1 = n;
    *p2 = n + 1;

    while (!IsPrime(*p1))
        --*p1;

    while (!IsPrime(*p2))
        ++*p2;
}

int main()
{
    int n;
    int p1;
    int p2;

    printf("Digite N: ");
    scanf("%d", &n);

    F(n, &p1, &p2);

    printf("Maior primo antes de N: %d\n", p1);
    printf("Maior primo depois de N: %d\n", p2);

    return 0;
}