/**
 * Author: Gian Carlo Bata
 * Date: 2024-06-10
 * Description: Header file for helper functions in blur.c
 */

#ifndef BLUR_H
#define BLUR_H

#include <stddef.h>

#include "bmp.h"

#define WEIGHT_SIZE 9

static void copy_image(int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE copy[height][width]);

static void blur_pixel(RGBTRIPLE *pixel, RGBTRIPLE *weights, size_t size);

static void populate_weights(size_t *size, int i, int j, int height, int width, RGBTRIPLE copy[height][width], RGBTRIPLE weights[WEIGHT_SIZE]);

#endif