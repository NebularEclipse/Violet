#include <stddef.h>

#include "../include/blur.h"
#include "../include/copy_image.h"
#include "../include/filter.h"

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    copy_image(height, width, image, copy);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE weights[WEIGHT_SIZE];
            size_t size;

            populate_weights(&size, i, j, height, width, copy, weights);
            blur_pixel(&image[i][j], weights, size);
        }
    }

    return;
}

static void blur_pixel(RGBTRIPLE *pixel, RGBTRIPLE *pixels, size_t size)
{
    float blue, green, red;

    blue = green = red = 0.5;

    for (int i = 0; i < size; i++)
    {
        blue += pixels[i].rgbtBlue;
        green += pixels[i].rgbtGreen;
        red += pixels[i].rgbtRed;
    }

    pixel->rgbtBlue = blue / size;
    pixel->rgbtGreen = green / size;
    pixel->rgbtRed = red / size;

    return;
}

static void populate_weights(size_t *size, int i, int j, int height, int width,
                             RGBTRIPLE copy[height][width], RGBTRIPLE weights[WEIGHT_SIZE])
{
    int di[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int dj[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

    int k = 0;
    int counter = 0;

    for (int d = 0; d < WEIGHT_SIZE; d++)
    {
        int ni = i + di[d];
        int nj = j + dj[d];

        if (ni >= 0 && ni < height && nj >= 0 && nj < width)
        {
            weights[k] = copy[ni][nj];
            k++;
            counter++;
        }
    }

    *size = counter;

    return;
}
