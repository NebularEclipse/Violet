#ifndef BLUR_H
#define BLUR_H

#include "bmp.h"

#define WEIGHT_SIZE 9

/**
 * @brief Applies a blurring effect to a pixel.
 *
 * This function applies a blurring effect to a pixel by averaging the color values of nearby pixels weighted by provided weights.
 *
 * @param pixel A pointer to the RGBTRIPLE structure representing the pixel to be blurred.
 *              Must point to a properly initialized RGBTRIPLE structure.
 * @param weights A pointer to the array of RGBTRIPLE structures representing the weights used for blurring calculations.
 *                Must point to a properly initialized array of RGBTRIPLE structures.
 * @param size The size of the weights array.
 *
 * @note The function modifies the color values of the input pixel in place.
 *
 * @warning The size parameter must be the correct size of the weights array to avoid accessing out-of-bounds memory.
 *
 * @example
 * Example usage of the function:
 * ```
 * RGBTRIPLE pixel;
 * RGBTRIPLE weights[9];
 * size_t size = 9;
 * blur_pixel(&pixel, weights, size);
 * ```
 */
static void blur_pixel(RGBTRIPLE *pixel, RGBTRIPLE *weights, size_t size);

/**
 * @brief Populates weights for blurring calculations.
 *
 * This function populates weights for blurring calculations based on the position in the image.
 *
 * @param size A pointer to a counter outside function call.
 * @param i The row index of the pixel for which weights are being populated.
 * @param j The column index of the pixel for which weights are being populated.
 * @param height The height of the image.
 * @param width The width of the image.
 * @param copy The copy of the image pixels.
 * @param weights An array of RGBTRIPLE structures representing the weights for blurring calculations.
 *
 * @return void
 *
 * @note The function populates weights in the weights array based on the surrounding pixels.
 *
 * @warning The function assumes that the copy and weights arrays are properly initialized and have sufficient memory.
 *
 * @example
 * Example usage of the function:
 * ```
 * int i, j;
 * int height, width;
 * RGBTRIPLE copy[height][width];
 * RGBTRIPLE weights[9];
 * 
 * populate_weights(i, j, height, width, copy, weights);
 * ```
 */
static void populate_weights(size_t *size, int i, int j, int height, int width, RGBTRIPLE copy[height][width], RGBTRIPLE weights[WEIGHT_SIZE]);

#endif