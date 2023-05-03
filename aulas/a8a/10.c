#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool IsPrime(int n)
{
    for (int divisor = 2; divisor < n; divisor++)
    {
        if (n % divisor == 0)
        {
            return false;
        }
    }

    return n > 1;
}

void Decompose(int n)
{
    int prime = 2;

    while (n != 1)
    {

        if (IsPrime(prime))
        {
            int multiplicity = 0;

            while (n % prime == 0)
            {
                n /= prime;
                multiplicity++;
            }
            
            if (multiplicity > 0)
            {
                printf("fator %d multiplicidade %d\n", prime, multiplicity);
            }
        }


        prime++;
    }

}

int main()
{
    int n;

    printf("Digite um numero para decompor: ");
    scanf("%d", &n);

    Decompose(n);
    
    return 0;
}