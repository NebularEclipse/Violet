#include "../include/filter.h"
#include "../include/swap_pixels.h"

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
