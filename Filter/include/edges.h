/**
 * Author: Gian Carlo Bata
 * Date: 2024-06-11
 * Description: Header file for helper functions in blur.c
 */

#ifndef EDGES_H
#define EDGES_H

#include "bmp.h"

/**
 * @brief Applies the Sobel edge detection filter to a pixel in an image.
 *
 * This function calculates the new value of a pixel at position (i, j) in an image by applying
 * the Sobel edge detection filter. The filter uses convolution operations with the Sobel kernels
 * to determine the intensity of edges at that pixel. The resulting values replace the original
 * pixel values.
 *
 * @param i The row index of the pixel to be processed.
 * @param j The column index of the pixel to be processed.
 * @param height The height of the image.
 * @param width The width of the image.
 * @param pixel A pointer to an RGBTRIPLE structure representing the pixel to be processed.
 *              This pixel will be modified in place.
 * @param copy A 2D array of RGBTRIPLE structures representing a copy of the original image.
 *             This is used to read the neighboring pixels for the convolution operation.
 *
 * @return void
 *
 * @note Ensure that the `copy` array is properly initialized and contains the original image data.
 *       The `pixel` pointer should point to the pixel at position (i, j) in the original image.
 *
 * @warning This function does not perform any bounds checking on the indices (i, j). It is the caller's
 *          responsibility to ensure that these indices are within the valid range of the image dimensions.
 *
 * @example
 * Example usage of the function:
 * ```
 * RGBTRIPLE image[height][width];
 * RGBTRIPLE copy[height][width];
 * 
 * int i = 10, j = 20;
 * edges_pixel(i, j, height, width, &image[i][j], copy);
 * ```
 */
static void edges_pixel(int i, int j, int height, int width, RGBTRIPLE *pixel, RGBTRIPLE copy[height][width]);

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