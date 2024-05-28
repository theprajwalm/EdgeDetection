#!/usr/bin/env python

import argparse
from PIL import Image

def convert_to_pgm_p2(input_image_path, output_image_path):
    try:
        # Open the input image
        img = Image.open(input_image_path)

        # Convert the image to grayscale
        gray_img = img.convert('L')

        # Get image dimensions
        width, height = gray_img.size

        # Maximum grayscale value
        max_gray = 255

        # Open the output file for writing
        with open(output_image_path, 'w') as f:
            # Write the PGM header
            f.write("P2\n")
            f.write(f"{width} {height}\n")
            f.write(f"{max_gray}\n")

            # Write pixel values
            for y in range(height):
                for x in range(width):
                    pixel_value = gray_img.getpixel((x, y))
                    f.write(f"{pixel_value} ")
                f.write("\n")

        print(f"Image converted to PGM P2: {output_image_path}")
    except Exception as e:
        print(f"Error: {e}")

def main():
    # Set up argument parsing
    parser = argparse.ArgumentParser(description='Convert an image file to PGM P2 format.')
    parser.add_argument('input', help='Path to the input image file')
    parser.add_argument('output', help='Path to save the output PGM file')

    # Parse the command-line arguments
    args = parser.parse_args()

    # Perform the conversion
    convert_to_pgm_p2(args.input, args.output)

if __name__ == "__main__":
    main()
