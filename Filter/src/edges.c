#include <math.h>

#include "../include/copy_image.h"
#include "../include/edges.h"
#include "../include/filter.h"

void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    copy_image(height, width, image, copy);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            edges_pixel(i, j, height, width, &image[i][j], copy);
        }
    }

    return;
}

static void edges_pixel(int i, int j, int height, int width, RGBTRIPLE *pixel, RGBTRIPLE copy[height][width])
{
    float x_blue, y_blue, x_green, y_green, x_red, y_red;
    x_blue = y_blue = x_green = y_green = x_red = y_red = 0;

    int Gx[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int Gy[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};

    int di[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int dj[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

    for (int d = 0; d < 9; d++)
    {
        int ni = i + di[d];
        int nj = j + dj[d];

        if (ni >= 0 && ni < height && nj >= 0 && nj < width)
        {
            x_blue += copy[ni][nj].rgbtBlue * Gx[d];
            y_blue += copy[ni][nj].rgbtBlue * Gy[d];
            x_green += copy[ni][nj].rgbtGreen * Gx[d];
            y_green += copy[ni][nj].rgbtGreen * Gy[d];
            x_red += copy[ni][nj].rgbtRed * Gx[d];
            y_red += copy[ni][nj].rgbtRed * Gy[d];
        }
    }

    pixel->rgbtBlue = threshold(sqrt(pow(x_blue, 2) + pow(y_blue, 2)));
    pixel->rgbtGreen = threshold(sqrt(pow(x_green, 2) + pow(y_green, 2)));
    pixel->rgbtRed = threshold(sqrt(pow(x_red, 2) + pow(y_red, 2)));

    return;
}

static BYTE threshold(double x)
{
    return (x < 0) ? 0 : ((x > 255) ? 255 : 0.5 + x);
}
