# Edge Detection

This project implements an edge detection algorithm in C. The program processes an image to highlight edges by following these steps:

1. **Blurring**: Apply Gaussian blur to reduce noise.
2. **Edge Detection**: Use Sobel operator to find edges.
3. **Gradient Magnitude**: Calculate gradient magnitude to identify intensity changes.
4. **Thresholding**: Highlight significant edges based on a threshold.

## How to Run
1. Compile the program using a C compiler.
2. Run the executable with the image file as input.

## Functions
- `apply_threshold`: Applies a threshold to highlight edges.
- `gradient_magnitude`: Calculates the gradient magnitude of the image.
- `scale_image`: Scales the image grayscale values.
- `convolve`: Performs convolution with a given kernel.

## Usage
```bash
gcc -o edge_detection edge_detection.c
./edge_detection input_image.bmp output_image.bmp
