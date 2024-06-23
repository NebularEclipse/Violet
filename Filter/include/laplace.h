/**
 * Author: Gian Carlo Bata
 * Date: 2024-06-23
 * Description: Header file for helper functions in edges.c
 */

#ifndef LAPLACE_H
#define LAPLACE_H

#include "bmp.h"

#define KERNEL_SIZE 9

static void
laplacian_edge_pixel
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
