#include "../include/filter.h"
#include "../include/sepia.h"

void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepia_pixel(&image[i][j]);
        }
    }
    
    return;
}

static void sepia_pixel(RGBTRIPLE *pixel)
{
    int sepia_blue  = 0.5 + (.272 * pixel->rgbtRed + .534 * pixel->rgbtGreen + .131 * pixel->rgbtBlue);
    int sepia_green = 0.5 + (.349 * pixel->rgbtRed + .686 * pixel->rgbtGreen + .168 * pixel->rgbtBlue);
    int sepia_red   = 0.5 + (.393 * pixel->rgbtRed + .769 * pixel->rgbtGreen + .189 * pixel->rgbtBlue);

    pixel->rgbtBlue  = threshold(sepia_blue);
    pixel->rgbtGreen = threshold(sepia_green);
    pixel->rgbtRed   = threshold(sepia_red);

    return;
}

static BYTE threshold(int x)
{
    return (x < 0) ? 0 : ((x > 255) ? 255 : x);
}