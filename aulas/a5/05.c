#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    const double mercury_gravity = 0.37;    
    const double venus_gravity = 0.88;
    const double mars_gravity = 0.38;
    const double jupiter_gravity = 2.64;
    const double saturn_gravity = 1.15;
    const double uranus_gravity = 1.17;

    double weight;
    int planet;

    printf("Planetas: \n");
    printf("1) Mercurio\n");
    printf("2) Venus\n");
    printf("3) Marte\n");
    printf("4) Jupiter\n");
    printf("5) Saturno\n");
    printf("6) Urano\n");
    
    printf("\nDigite o peso na Terra e o numero do planeta: ");
    scanf("%lf %d", &weight, &planet);

    double gravity;
    bool valid = true;

    switch (planet)
    {
        case 1:
            gravity = mercury_gravity;
            break;
        case 2:
            gravity = venus_gravity;
            break;
        case 3:
            gravity = mars_gravity;
            break;
        case 4:
            gravity = jupiter_gravity;
            break;
        case 5:
            gravity = saturn_gravity;
            break;
        case 6:
            gravity = uranus_gravity;
            break;
        default:
            valid = false;
    } 

    if (valid)
    {
        double planet_weight = weight * gravity;
        
        printf("Gravidade no planeta: %lfN\n", planet_weight);
    }
    else
    {
        printf("Planeta invalido\n");
    }

    return 0;
}
