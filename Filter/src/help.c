#include <stdio.h>

#include "../include/help.h"

void print_help(void)
{
    printf("Usage: ./filter [flag] infile outfile\n");
    printf("Options:\n");
    printf("  -b value   Apply a Box Blur filter of radius 1.\n");
    printf("  -e value   Apply Sobel Edge Detection filter.\n");
    printf("  -d value   Apply Directional Difference filter.\n");
    printf("  -g value   Apply Grayscale filter.\n");
    printf("  -r value   Apply Horizontal Reflection filter.\n");
    printf("  -s value   Apply Sepia filter.\n\n");
    printf("  -h         Display this help message\n");
    printf("Usage: ./filter -h\n");
    // Add more filters as needed
}