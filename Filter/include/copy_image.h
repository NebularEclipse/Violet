/**
 * Author: Gian Carlo Bata
 * Date: 2024-06-22
 * Description: Header file for copy_image function in copy_image.c
 */

#ifndef COPY_IMAGE_H
#define COPY_IMAGE_H

#include "bmp.h"

void
copy_image
(
    int height,
    int width,
    RGBTRIPLE image[height][width],
    RGBTRIPLE copy[height][width]
);

#endif
