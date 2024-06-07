#include "../include/filter.h"
#include "../include/grayscale.h"

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            grayscale_pixel(&image[i][j]);
        }
    }
    
    return;
}

static void grayscale_pixel(RGBTRIPLE *pixel)
{
    BYTE mean = (pixel->rgbtBlue + pixel->rgbtGreen + pixel->rgbtRed + 1.5) / 3;

    pixel->rgbtBlue   =  mean;
    pixel->rgbtGreen  =  mean;
    pixel->rgbtRed    =  mean;
    
    return;
}