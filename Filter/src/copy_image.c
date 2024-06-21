#include "../include/bmp.h"
#include "../include/copy_image.h"

void copy_image(int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE copy[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
}
