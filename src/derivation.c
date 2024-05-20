#include "derivation.h"

#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "convolution.h"
#include "image.h"

void gradient_magnitude(float *result, const float *d_x, const float *d_y,
                        int w, int h) {
    (void)result;
    (void)d_x;
    (void)d_y;
    (void)w;
    (void)h;

    // TODO: Implement me!
    for (int x = 0; x < w; x++){ //stops when width = x
        for (int y = 0; y < h; y++){ //stops when height = y

        float dx = d_x[x + y * w]; //get dx
        float dy = d_y[x + y * w]; //get dy

        float square = dx * dx + dy * dy; //dx2 + dy2
        float value = sqrt(square); //squareroot

        result[x+ y * w] = value; //storing the grad into the result
        }
    }
}

const float sobel_x[9] = {1, 0, -1, 2, 0, -2, 1, 0, -1};

const float sobel_y[9] = {1, 2, 1, 0, 0, 0, -1, -2, -1};

void derivation_x_direction(float *result, const float *img, int w, int h) {
    convolve(result, img, w, h, sobel_x, 3, 3);
}

void derivation_y_direction(float *result, const float *img, int w, int h) {
    convolve(result, img, w, h, sobel_y, 3, 3);
}
