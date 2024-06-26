#include "../include/bmp.h"
#include "../include/filter.h"
#include "../include/help.h"
#include "../include/options.h"

void filter(int n, int height, int width, RGBTRIPLE image[height][width], char opt)
{
    switch (opt)
    {
        case 'b':
            mean_blur(n, height, width, image);
            break;

        case 'e':
            edges(height, width, image);
            break;
        
        case 'd':
            emboss(height, width, image);
            break;

        case 'g':
            grayscale(height, width, image);
            break;
        
        case 'l':
            laplacian_edge(height, width, image);
            break;

        case 'r':
            reflect(height, width, image);
            break;

        case 's':
            sepia(height, width, image);
            break;

        default:
            print_help();
            break;
    }

    return;
}
