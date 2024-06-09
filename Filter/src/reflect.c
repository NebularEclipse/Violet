#include "../include/filter.h"
#include "../include/reflect.h"

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            swap_pixels(&image[i][j], &image[i][width - j - 1]);
        }
    }

    return;
}

static void swap_pixels(RGBTRIPLE *a, RGBTRIPLE *b)
{
    RGBTRIPLE temp = *a;
    *a = *b;
    *b = temp;

    return;
}