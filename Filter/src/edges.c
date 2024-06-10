#include <math.h>
#include <stddef.h>

#include "../include/edges.h"
#include "../include/filter.h"

void edges(int height, int width, RGBTRIPLE image[height][width])
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
            RGBTRIPLE weights[WEIGHT_SIZE];
            size_t size;

            populate_weights(&size, i, j, height, width, copy, weights);
            edges_pixel(&image[i][j], weights, size);
        }
    }

    return;
}

static void edges_pixel(RGBTRIPLE *pixel, RGBTRIPLE *pixels, size_t size)
{
    float x_blue, y_blue, x_green, y_green, x_red, y_red;

    int Gx[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int Gy[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};

    x_blue = y_blue = x_green = y_green = x_red = y_red = 0;

    for (int i = 0; i < size; i++)
    {
        x_blue += pixels[i].rgbtBlue * Gx[i];
        y_blue += pixels[i].rgbtBlue * Gy[i];
        x_green += pixels[i].rgbtGreen * Gx[i];
        y_green += pixels[i].rgbtGreen * Gy[i];
        x_red += pixels[i].rgbtRed * Gx[i];
        y_red += pixels[i].rgbtRed * Gy[i];
    }

    pixel->rgbtBlue = threshold(sqrt(pow(x_blue, 2) + pow(y_blue, 2)));
    pixel->rgbtGreen = threshold(sqrt(pow(x_green, 2) + pow(y_green, 2)));
    pixel->rgbtRed = threshold(sqrt(pow(x_red, 2) + pow(y_red, 2)));

    return;
}

static void populate_weights(size_t *size, int i, int j, int height, int width,
                             RGBTRIPLE copy[height][width], RGBTRIPLE weights[WEIGHT_SIZE])
{
    int di[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int dj[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

    int k = 0;
    int counter = 0;

    for (int d = 0; d < 9; d++)
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

static BYTE threshold(double x)
{
    return (x < 0) ? 0 : ((x > 255) ? 255 : 0.5 + x);
}
