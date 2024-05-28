#include "convolution.h"

#include <stdlib.h>

#include "image.h"

void convolve(float *result, const float *img, int w, int h,
              const float *matrix, int w_m, int h_m) {
    // (void)result;
    // (void)img;
    // (void)w;
    // (void)h;
    // (void)matrix;
    // (void)w_m;
    // (void)h_m;

    // TODO: Implement me!
    int k_half_w = w_m / 2;
    int k_half_h = h_m / 2;

    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            float sum = 0.0f;

            // Apply the matrix to the pixel (x, y)
            for (int ky = -k_half_h; ky <= k_half_h; ++ky) {
                for (int kx = -k_half_w; kx <= k_half_w; ++kx) {
                    int px = x + kx;
                    int py = y + ky;
                    float pixel_value = get_pixel_value(img, w, h, px, py);
                    float matrix_value = matrix[(ky + k_half_h) * w_m + (kx + k_half_w)];
                    sum += pixel_value * matrix_value;
                }
            }

            // Store the result in the result image
            result[y * w + x] = sum;
        }
    }
}
