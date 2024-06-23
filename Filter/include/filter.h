#ifndef FILTER_H
#define FILTER_H

#include "bmp.h"

// Convert image to grayscale
void
grayscale
(
    int height,
    int width,
    RGBTRIPLE image[height][width]
);

// Convert image to sepia
void
sepia
(
    int height,
    int width,
    RGBTRIPLE image[height][width]
);

// Reflect image horizontally
void
reflect
(
    int height,
    int width,
    RGBTRIPLE image[height][width]
);

// Blur image
void
mean_blur
(
    int n,
    int height,
    int width,
    RGBTRIPLE image[height][width]
);

// Detect edges
void
edges
(
    int height,
    int width,
    RGBTRIPLE image[height][width]
);

// Emboss image
void
emboss
(
    int height,
    int width,
    RGBTRIPLE image[height][width]
);

// Laplacian Edge Detection
void
laplacian_edge
(
    int height,
    int width,
    RGBTRIPLE image[height][width]
);

#endif
