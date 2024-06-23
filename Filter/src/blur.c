#include <math.h>
#include <stddef.h>

#include "../include/blur.h"
#include "../include/copy_image.h"
#include "../include/filter.h"

void mean_blur(int n, int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    copy_image(height, width, image, copy);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            mean_blur_pixel(abs(n), i, j, height, width, &image[i][j], copy);
        }
    }

    return;
}

static void mean_blur_pixel(int n, int i, int j, int height, int width, RGBTRIPLE *pixel, RGBTRIPLE copy[height][width])
{
    float blue, green, red;
    blue = green = red = 0.5;

    size_t size = 0;

    for (int k = -n; k <= n; k++)
    {
        for (int l = -n; l <= n; l++)
        {
            int ni = i + k;
            int nj = j + l;

            if (ni >= 0 && ni < height && nj >= 0 && nj < width)
            {
                blue += copy[ni][nj].rgbtBlue;
                green += copy[ni][nj].rgbtGreen;
                red += copy[ni][nj].rgbtRed;

                size++;
            }
        }
    }

    pixel->rgbtBlue = blue / size;
    pixel->rgbtGreen = green / size;
    pixel->rgbtRed = red / size;

    return;
}
