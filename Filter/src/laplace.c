#include <math.h>

#include "../include/copy_image.h"
#include "../include/filter.h"
#include "../include/laplace.h"

void laplacian_edge(int height, int width, RGBTRIPLE image[height][width])
{
    grayscale(height, width, image);
    
    RGBTRIPLE copy[height][width];
    copy_image(height, width, image, copy);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            laplacian_edge_pixel(i, j, height, width, &image[i][j], copy);
        }
    }

    return;
}

static void laplacian_edge_pixel(int i, int j, int height, int width, RGBTRIPLE *pixel, RGBTRIPLE copy[height][width])
{
    float blue = 0, green = 0, red = 0;

    int em[] = {0, -1, 0, -1, 4, -1, 0, -1, 0};

    int di[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int dj[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

    for (int d = 0; d < KERNEL_SIZE; d++)
    {
        int ni = i + di[d];
        int nj = j + dj[d];

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
    return (x < 0) ? 0 : ((x > 255) ? 255 : 0.5 + x);
}
