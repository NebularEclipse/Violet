#include <math.h>

#include "../include/emboss.h"
#include "../include/filter.h"

void emboss(int height, int width, RGBTRIPLE image[height][width])
{
    grayscale(height, width, image);

    RGBTRIPLE copy[height][width];
    copy_image(height, width, image, copy);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            emboss_pixel(i, j, height, width, &image[i][j], copy);
        }
    }

    return;
}

static void copy_image(int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE copy[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
}

static void emboss_pixel(int i, int j, int height, int width, RGBTRIPLE *pixel, RGBTRIPLE copy[height][width])
{
    float blue = 0, green = 0, red = 0;

    int em[] = {2, 1, 0, 1, 0, -1, 0, -1, -2};

    for (int d = 0; d < 9; d++)
    {
        int ni = i + em[d];
        int nj = j + em[d];

        if (ni >= 0 && ni < height && nj >= 0 && nj < width)
        {
            blue += copy[ni][nj].rgbtBlue * em[d];
            green += copy[ni][nj].rgbtGreen * em[d];
            red += copy[ni][nj].rgbtRed * em[d];
        }
    }

    pixel->rgbtBlue = threshold(0.5 + blue);
    pixel->rgbtGreen = threshold(0.5 + green);
    pixel->rgbtRed = threshold(0.5 + red);

    return;
}

static BYTE threshold(double x)
{
    return fmax(0, fmin(255, x + 128));
}
