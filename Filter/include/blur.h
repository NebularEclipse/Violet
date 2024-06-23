/**
 * Author: Gian Carlo Bata
 * Date: 2024-06-10
 * Description: Header file for helper functions in blur.c
 */

#ifndef BLUR_H
#define BLUR_H

#include <stddef.h>

#include "bmp.h"

#define KERNEL_SIZE 9

static void
mean_blur_pixel
(
    int n,
    int i,
    int j,
    int height,
    int width,
    RGBTRIPLE *pixel,
    RGBTRIPLE copy[height][width]
);

#endif
