/**
 * Author: Gian Carlo Bata
 * Date: 2024-06-21
 * Description: Header file for helper functions in options.c
 */

#ifndef OPTIONS_H
#define OPTIONS_H

#include "bmp.h"

void filter(int height, int width, RGBTRIPLE image[height][width], char opt);

#endif