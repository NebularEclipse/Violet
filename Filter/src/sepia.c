#include "../include/filter.h"

void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepia_blue =
                0.5 + (.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            int sepia_green =
                0.5 + (.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepia_red =
                0.5 + (.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);

            image[i][j].rgbtBlue = (sepia_blue < 0) ? 0 : ((sepia_blue > 255) ? 255 : sepia_blue);
            image[i][j].rgbtGreen = (sepia_green < 0) ? 0 : ((sepia_green > 255) ? 255 : sepia_green);
            image[i][j].rgbtRed = (sepia_red < 0) ? 0 : ((sepia_red > 255) ? 255 : sepia_red);
        }
    }
    
    return;
}
