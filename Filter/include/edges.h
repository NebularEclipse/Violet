/**
 * Author: Gian Carlo Bata
 * Date: 2024-06-11
 * Description: Header file for helper functions in blur.c
 */

#ifndef EDGES_H
#define EDGES_H

#include <stddef.h>

#include "bmp.h"

#define WEIGHT_SIZE 9

/**
 * @brief Applies the Sobel edge detection filter to a pixel.
 *
 * This function calculates the new value of a pixel by applying the Sobel edge detection
 * filter. The filter uses a convolution operation with the provided Sobel kernels (weights)
 * to determine the intensity of edges at that pixel. The resulting values replace the original
 * pixel values.
 *
 * @param pixel A pointer to an RGBTRIPLE structure representing the pixel to be processed.
 *              This pixel will be modified in place.
 * @param weights A pointer to an array of RGBTRIPLE structures representing the Sobel filter
 *                weights to be used in the convolution operation. This typically includes the
 *                horizontal (Gx) and vertical (Gy) Sobel kernels.
 * @param size The size of the weights array. For Sobel filters, this is expected to be 2 (one
 *             for Gx and one for Gy), where each is typically a 3x3 kernel.
 *
 * @return void
 *
 * @note Ensure that the pixel pointer is valid and points to a properly initialized RGBTRIPLE
 *       structure. The weights array should be properly initialized and contain the correct values
 *       for the Sobel edge detection kernels.
 *
 * @warning This function does not perform any bounds checking on the pixel or weights pointers.
 *          It is the caller's responsibility to ensure that these pointers are valid and within
 *          the bounds of allocated memory.
 *
 * @example
 * Example usage of the function:
 * ```
 * RGBTRIPLE pixel;
 * RGBTRIPLE weights[9];
 * size_t size = 9;
 * // Initialize pixel and weights data...
 * edges_pixel(&pixel, weights, size);
 * ```
 */
static void edges_pixel(RGBTRIPLE *pixel, RGBTRIPLE *weights, size_t size);

/**
 * @brief Populates weights for edges detection calculations.
 *
 * This function populates weights for blurring calculations based on the position in the image.
 *
 * @param size A pointer to a counter outside function call.
 * @param i The row index of the pixel for which weights are being populated.
 * @param j The column index of the pixel for which weights are being populated.
 * @param height The height of the image.
 * @param width The width of the image.
 * @param copy The copy of the image pixels.
 * @param weights An array of RGBTRIPLE structures representing the weights for blurring
 *                calculations.
 *
 * @return void
 *
 * @note The function populates weights in the weights array based on the surrounding pixels.
 *
 * @warning The function assumes that the copy and weights arrays are properly initialized and have
 *          sufficient memory.
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
static void populate_weights(size_t *size, int i, int j, int height, int width,
                             RGBTRIPLE copy[height][width], RGBTRIPLE weights[WEIGHT_SIZE]);

/**
 * @brief Returns a threshold value clamped within the range [0, 255].
 *
 * This function calculates a threshold value based on the input parameter `x`.
 * If the calculated value is outside the range [0, 255], it is clamped to the nearest boundary.
 *
 * @param x An floating point value representing the input parameter for threshold calculation.
 * @return BYTE (uint8_t) representing the calculated threshold value clamped within the range
 *         [0, 255].
 *
 * @note The function clamps the calculated threshold value to the range [0, 255].
 *
 * @warning None.
 *
 * @example
 * Example usage of the function:
 * ```
 * RGBTRIPLE pixel;
 * 
 * float x_blue, y_blue;
 * 
 * pixel->rgbtBlue = threshold(sqrt(pow(x_blue, 2) + pow(y_blue, 2)));
 * ```
 */
static BYTE threshold(double x);

#endif