#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

double Min(double a, double b)
{
    return a < b ? a : b;
}

double Max(double a, double b)
{
    return a > b ? a : b;
}

double GetPictureFittingLength(double album_min, double picture_height, double picture_width)
{
    double picture_min = Min(picture_height, picture_width);
    double picture_max = Max(picture_height, picture_width);

    if (picture_max <= album_min)
    {
        return picture_min;
    }

    if (picture_min <= album_min)
    {
        return picture_max;
    }

    return -1.0;
}

int main()
{
    double album_height, album_width;
    double picture1_height, picture1_width;
    double picture2_height, picture2_width;

    printf("Digite as dimensoes do album: ");
    scanf("%lf %lf", &album_height, &album_width);

    printf("Digite as dimensoes da foto 1: ");
    scanf("%lf %lf", &picture1_height, &picture1_width);

    printf("Digite as dimensoes da foto 2: ");
    scanf("%lf %lf", &picture2_height, &picture2_width);

    double album_min = Min(album_height, album_width);
    double album_max = Max(album_height, album_width);

    double picture1_fitting_length = GetPictureFittingLength(album_min, picture1_height, picture1_width);
    double picture2_fitting_length = GetPictureFittingLength(album_min, picture2_height, picture2_width);

    double required_length = picture1_fitting_length + picture2_fitting_length;

    if (picture1_fitting_length != -1 && picture2_fitting_length != -1 && required_length <= album_max)
    {
        printf("S\n");
    }
    else
    {
        printf("N\n");
    }

    return 0;
}
