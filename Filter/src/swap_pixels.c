#include "../include/bmp.h"
#include "../include/swap_pixels.h"

void swap_pixels(RGBTRIPLE *a, RGBTRIPLE *b)
{
    RGBTRIPLE temp = *a;
    *a = *b;
    *b = temp;

    return;
}
