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

    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            RGBTRIPLE pixels[]  =  {copy[i - 1][j - 1], copy[i - 1][j], copy[i - 1][j + 1],
                                    copy[i][j - 1],     copy[i][j],     copy[i][j + 1], 
                                    copy[i + 1][j - 1], copy[i + 1][j], copy[i + 1][j + 1]};
            blur_pixel(&image[i][j], pixels, 9);
        }
    }

    for (int i = 1; i < width - 1; i++)
    {
        RGBTRIPLE pixels[] =   {copy[0][i - 1], copy[0][i], copy[0][i + 1], 
                                copy[1][i - 1], copy[1][i], copy[1][i + 1]};
        blur_pixel(&image[0][i], pixels, 6);
    }

    for (int i = 1; i < width - 1; i++)
    {
        RGBTRIPLE pixels[] =   {copy[height - 1][i - 1], copy[height - 1][i], copy[height - 1][i + 1], 
                                copy[height - 2][i - 1], copy[height - 2][i], copy[height - 2][i + 1]};
        blur_pixel(&image[height - 1][i], pixels, 6);
    }

    for (int i = 1; i < height - 1; i++)
    {
        RGBTRIPLE pixels[] =   {copy[i - 1][0], copy[i][0], copy[i + 1][0], 
                                copy[i - 1][1], copy[i][1], copy[i + 1][1]};
        blur_pixel(&image[i][0], pixels, 6);
    }

    for (int i = 1; i < height - 1; i++)
    {
        RGBTRIPLE pixels[] =   {copy[i - 1][width - 1], copy[i][width - 1], copy[i + 1][width - 1], 
                                copy[i - 1][width - 2], copy[i][width - 2], copy[i + 1][width - 2]};
        blur_pixel(&image[i][width - 1], pixels, 6);
    }

    int a[4][4] =  {{0,          0,          1,  1},
                    {0,          width - 1,  1, -1},
                    {height - 1, 0,         -1,  1},
                    {height - 1, width - 1, -1, -1}};

    for (int i = 0; i < 4; i++)
    {
        RGBTRIPLE corner[4];
        populate_corner(height, width, 4, copy, corner, a[i]);
        blur_pixel(&image[a[i][0]][a[i][1]], corner, 4);
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

static void populate_corner(int height, int width, int size, RGBTRIPLE copy[height][width], RGBTRIPLE corner[size], int a[size])
{
    corner[0] = copy[a[0]][a[1]];
    corner[1] = copy[a[0]][a[1] + a[3]];
    corner[2] = copy[a[0] + a[2]][a[1]];
    corner[3] = copy[a[0] + a[2]][a[1] + a[3]];

    return;
}
