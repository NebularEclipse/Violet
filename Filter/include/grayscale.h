#ifndef GRAYSCALE_H
#define GRAYSCALE_H

#include "bmp.h"

/**
 * @brief Applies the Grayscale filter on a pixel.
 *
 * The Grayscale filter takes the mean of the RGB (Red, Green, and Blue) color channels,
 * and replaces the original pixel values with this mean value.
 *
 * @param pixel A pointer to an RGBTRIPLE structure on which we want to apply the Grayscale filter.
 * @return void
 *
 * @note Ensure that the pixel pointer is valid and points to a properly initialized RGBTRIPLE structure.
 *
 * @warning This function does not perform any bounds checking on the pixel pointer.
 *
 * @example
 * Example usage of the function:
 * ```
 * RGBTRIPLE pixel;
 * 
 * grayscale_pixel(&pixel);
 * ```
 */
static void grayscale_pixel(RGBTRIPLE *pixel);

#endif