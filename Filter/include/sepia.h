#ifndef SEPIA_H
#define SEPIA_H

#include "bmp.h"

/**
 * @brief Applies the Sepia filter on a pixel.
 *
 * This function transforms the RGB (Red, Green, and Blue) color channels of a pixel
 * into sepia tones, simulating an old-fashioned photograph effect.
 *
 * @param pixel A pointer to an RGBTRIPLE structure representing the pixel to be transformed.
 *              Must point to a properly initialized RGBTRIPLE structure.
 * @return void
 *
 * @note The function does not perform any bounds checking on the pixel pointer.
 *       Ensure that the pixel pointer is valid and points to a properly initialized RGBTRIPLE
 *       structure.
 *
 * @warning This function modifies the pixel's color channels in place.
 *          Ensure that the input pixel data can be safely modified.
 *          This function does not check if the pixel pointer is NULL.
 *
 * @example
 * Example usage of the function:
 * ```
 * RGBTRIPLE pixel;
 * 
 * sepia_pixel(&pixel);
 * ```
 */

static void sepia_pixel(RGBTRIPLE *pixel);

/**
 * @brief Returns a threshold value clamped within the range [0, 255].
 *
 * This function calculates a threshold value based on the input parameter `x`.
 * If the calculated value is outside the range [0, 255], it is clamped to the nearest boundary.
 *
 * @param x An integer value representing the input parameter for threshold calculation.
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
 * int sepia_blue  = 0.5 + (.272 * pixel->rgbtRed + .534 * pixel->rgbtGreen + .131 *
 *                   pixel->rgbtBlue);
 * 
 * pixel.rgbtBlue = threshold(sepia_blue);
 * ```
 */
static BYTE threshold(int x);

#endif