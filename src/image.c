#include "image.h"

#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void apply_threshold(float *img, int w, int h, int T) {
    // (void)img;
    // (void)w;
    // (void)h;
    // (void)T;

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
    // (void)result;
    // (void)img;
    // (void)w;
    // (void)h;

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
    // (void)img;
    // (void)w;
    // (void)h;
    // (void)x;
    // (void)y;

    // TODO: Implement me!
    if (x < 0) {
        x = -x - 1;
    } else if (x >= w) {
        x = 2 * w - x - 1;
    }

    // Handle vertical mirroring
    if (y < 0) {
        y = -y - 1;
    } else if (y >= h) {
        y = 2 * h - y - 1;
    }

    // Return the pixel value at the mirrored coordinates
    return img[y * w + x];

    return 0;
}

float *array_init(int size) {
    (void)size;

    // TODO: Implement me!
    if(size <= 0){ // if size is negative
        return NULL;
    }
    float *array = (float *)malloc(size * sizeof(float)); // allocating memory in Heap
    if (array == 0) // if array is zero 
    {
        return NULL;
    }
    return array;
}

void array_destroy(float *m) {
    (void)m;

    // TODO: Implement me!
    if (m) //if something is there in m
    {
        free(m);
    }
    
}

float *read_image_from_file(const char *filename, int *w, int *h) {
    // (void)filename;
    // (void)w;
    // (void)h;

    // TODO: Implement me!
    FILE *file = fopen(filename, "r"); //opening a file

    if (file == 0){ //if file is empty
    return NULL;
    }

    //checking the format of a file
    char format[3]; //storing format 
    if (fscanf(file, "%2s",format) != 1 || strcmp(format, "P2") != 0) // if unsucessfull reading or format not equal to P2 then
    {
        fclose(file); //close file
        return NULL; //Error in header
    }
    
    //to skip comments in header
    char ch;
    while ((ch = fgetc(file)) == '#') 
    {
        while (fgetc(file) != '\n'); // Skip  entire  line
    }
    ungetc(ch, file); // can be skipped

    // reading the width and the height 
    if (fscanf(file, "%d %d", w, h) != 2 || *w <= 0 || *h <= 0)
    {
        fclose(file);
        return NULL;
    }

    // reading the maximum value
    int maximum;
    if (fscanf(file, "%d", &maximum) != 1 || maximum != 255) {
        fclose(file);
        return NULL; 
    }

    int size = (*w) * (*h); //height x width
    float *img = array_init(size); //allocating memory to store the img
    if (img == 0){
        fclose(file);
        return NULL; 
    }

    for (int i = 0; i < size; i++)
    {
        int pix;
        if (fscanf(file, "%d", &pix) != 1 || pix < 0 || pix > 255){
            array_destroy(img);
            fclose(file);
            return NULL;
        }
        img[i] = (float) pix; //storing the file pixel to img in heap
    }
    int extra_check;
    if (fscanf(file, "%d", &extra_check) == 1) {
        array_destroy(img);
        fclose(file);
        return NULL;
    }

    fclose(file); //closing the opened file.
    return img; // returning the image

}

void write_image_to_file(const float *img, int w, int h, const char *filename) {
    // (void)img;
    // (void)w;
    // (void)h;
    // (void)filename;

    // TODO: Implement me!
    FILE *file = fopen(filename, "w"); //opening a file

    if (!file){
        return;
    }
    fprintf(file, "P2\n"); //writing the format of the image
    fprintf(file, "%d %d\n", w, h); //writing the width and height
    fprintf(file, "255\n"); //writing maximum pixel in our case 255
    
     for (int i = 0; i < w * h; ++i) {
        fprintf(file, "%d\n", (int)img[i]);
    }
        
        fclose(file);
    }