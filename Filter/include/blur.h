#ifndef BLUR_H
#define BLUR_H

#include "bmp.h"

static void blur_pixel(RGBTRIPLE *pixel, RGBTRIPLE *pixels, size_t size);

static void populate_corner(int height, int width, int size, RGBTRIPLE copy[height][width], RGBTRIPLE corner[size], int a[size]);

#endif