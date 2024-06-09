#ifndef REFLECT_H
#define REFLECT_H

#include "bmp.h"

/**
 * @brief Swaps the values of two pixels.
 *
 * This function swaps the RGB (Red, Green, and Blue) color values of two pixels.
 *
 * @param a A pointer to the first RGBTRIPLE structure representing the first pixel.
 *          Must point to a properly initialized RGBTRIPLE structure.
 * @param b A pointer to the second RGBTRIPLE structure representing the second pixel.
 *          Must point to a properly initialized RGBTRIPLE structure.
 * @return void
 *
 * @note The function modifies the values of both pixels in place.
 *
 * @warning None.
 *
 * @example
 * Example usage of the function:
 * ```
 * RGBTRIPLE a, b;
 * 
 * swap_pixels(&a, &b);
 * ```
 */
static void swap_pixels(RGBTRIPLE *a, RGBTRIPLE *b);

#endif