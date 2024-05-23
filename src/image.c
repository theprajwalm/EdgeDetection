#include "image.h"

#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void apply_threshold(float *img, int w, int h, int T) {
    (void)img;
    (void)w;
    (void)h;
    (void)T;

    // TODO: Implement me!
    for (int i = 0; i < w * h ; i++){ // loop stops when i >= area of the image

    if (img[i] <= T){ //if pixel <= Threshold 
        img[i] = 0; //black
    }
    else{
        img[i] = 255; //white
    }
    } 

}

void scale_image(float *result, const float *img, int w, int h) {
    (void)result;
    (void)img;
    (void)w;
    (void)h;

    // TODO: Implement me!
    float max = img[0]; //intial maximum value
    float min = img[0]; //intial minimum value

    for (int i = 1; i < w * h; i++) //from 1 to last pixel value
    {
        if (img[i] > max) //if greater than maximum
        {
            max = img[i]; //new maximum
        }
        else if (img[i] < min) //if less than minimum
        {
            min = img[i]; //new minimum
        }
    }


    if (max == min) // if max = min
    {
        for (int i = 0; i < w * h; i++)
        {
            result[i] = 0; // black
        }
    }
    else
    {
        for (int i = 0; i < w * h; i++)
        {
            result[i] = ((img[i] - min) / (max - min)) * 255; // Scaled gray-scale values
        }
    }
}



float get_pixel_value(const float *img, int w, int h, int x, int y) {
    (void)img;
    (void)w;
    (void)h;
    (void)x;
    (void)y;

    // TODO: Implement me!
    

    return 0;
}

float *array_init(int size) {
    (void)size;

    // TODO: Implement me!

    return NULL;
}

void array_destroy(float *m) {
    (void)m;

    // TODO: Implement me!
}

float *read_image_from_file(const char *filename, int *w, int *h) {
    (void)filename;
    (void)w;
    (void)h;

    // TODO: Implement me!

    return NULL;
}

void write_image_to_file(const float *img, int w, int h, const char *filename) {
    (void)img;
    (void)w;
    (void)h;
    (void)filename;

    // TODO: Implement me!
}