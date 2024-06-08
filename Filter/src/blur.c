#include <math.h>

#include "../include/filter.h"
#include "../include/blur.h"

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE weights[9];
            populate_weights(i, j, height, width, copy, weights);
            blur_pixel(&image[i][j], weights, neighbors(i, j, height, width));
        }
    }

    return;
}

static void blur_pixel(RGBTRIPLE *pixel, RGBTRIPLE *pixels, size_t size)
{
    float blue, green, red;
    blue = green = red = 0;
    for (int i = 0; i < size; i++)
    {
        blue   +=  pixels[i].rgbtBlue;
        green  +=  pixels[i].rgbtGreen;
        red    +=  pixels[i].rgbtRed;
    }

    blue   =  round(blue / (float) size);
    green  =  round(green / (float) size);
    red    =  round(red / (float) size);

    pixel->rgbtBlue   =  blue;
    pixel->rgbtGreen  =  green;
    pixel->rgbtRed    =  red;

    return;
}

static void populate_weights(int i, int j, int height, int width, RGBTRIPLE copy[height][width], RGBTRIPLE weights[9])
{
    int di[] = {-1, -1, -1,  0,  0,  0,  1,  1,  1};
    int dj[] = {-1,  0,  1, -1,  0,  1, -1,  0,  1};

    int k = 0;
    for (int d = 0; d < 9; d++)
    {
        int ni = i + di[d];
        int nj = j + dj[d];

        if (ni >= 0 && ni < height && nj >= 0 && nj < width)
        {
            weights[k] = copy[ni][nj];
            k++;
        }
    }

    return;
}

static int neighbors(int i, int j, int height, int width)
{
    int count = 0;

    int di[] = {-1, -1, -1,  0,  0,  0,  1,  1,  1};
    int dj[] = {-1,  0,  1, -1,  0,  1, -1,  0,  1};

    for (int d = 0; d < 9; d++)
    {
        int ni = i + di[d];
        int nj = j + dj[d];

        if (ni >= 0 && ni < height && nj >= 0 && nj < width)
        {
            count++;
        }
    }

    return count;
}