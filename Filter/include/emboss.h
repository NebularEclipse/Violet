/**
 * Author: Gian Carlo Bata
 * Date: 2024-06-11
 * Description: Header file for helper functions in emboss.c
 */

#ifndef EMBOSS_H
#define EMBOSS_H

#include "bmp.h"

#define KERNEL_SIZE 9

static void
emboss_pixel
(
    int i,
    int j,
    int height,
    int width,
    RGBTRIPLE *pixel,
    RGBTRIPLE copy[height][width]
);

static BYTE
threshold
(
    double x
);

#endif
