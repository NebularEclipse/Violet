/**
 * Author: Gian Carlo Bata
 * Date: 2024-06-11
 * Description: Header file for helper functions in edges.c
 */

#ifndef EDGES_H
#define EDGES_H

#include "bmp.h"

static void edges_pixel(int i, int j, int height, int width, RGBTRIPLE *pixel, RGBTRIPLE copy[height][width]);

static BYTE threshold(double x);

#endif