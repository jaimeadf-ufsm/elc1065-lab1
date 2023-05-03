#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int n;

    int smaller_100_1000 = __INT_MAX__;
    int sum_100_1000 = 0;
    int n_100_1000 = 0;
    int sum = 0;

    do {
        scanf("%d", &n);

        if (n != -1)
        {
            if (n > 100 && n < 1000)
            {
                if (smaller_100_1000 > n)
                {
                    smaller_100_1000 = n;
                }

                sum_100_1000 += n;
                n_100_1000++;
            }

            sum += n;
        }
    } while (n != -1);

    double average_100_1000 = (double)sum_100_1000 / n_100_1000;

    printf("Menor valor entre 100 e 1000: %d\n", smaller_100_1000);
    printf("Media dos valores entre 100 e 1000: %lf\n", average_100_1000);
    printf("Soma dos valores entre 100 e 1000: %d\n", sum_100_1000);
    printf("Soma total: %d\n", sum);

    return 0;
}