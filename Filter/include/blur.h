#ifndef BLUR_H
#define BLUR_H

#include "bmp.h"

static void blur_pixel(RGBTRIPLE *pixel, RGBTRIPLE *pixels, size_t size);

static void populate_weights(int i, int j, int height, int width, RGBTRIPLE copy[height][width], RGBTRIPLE weights[9]);

static int neighbors(int i, int j, int height, int width);

#endif