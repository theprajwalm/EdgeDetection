import argparse
from PIL import Image
import os

def convert_pgm_to_png(input_image_path, output_image_path):
    try:
        # Open the PGM image
        img = Image.open(input_image_path)

        # Ensure the image is in 'L' mode (grayscale)
        img = img.convert('L')

        # Save the image as PNG
        img.save(output_image_path, format='PNG')
        print(f"Converted {input_image_path} to {output_image_path}")
    except Exception as e:
        print(f"Error: {e}")

def main():
    # Set up argument parsing
    parser = argparse.ArgumentParser(description='Convert PGM files to PNG format.')
    parser.add_argument('input', help='Path to the input PGM file')
    parser.add_argument('output', nargs='?', help='Path to save the output PNG file (optional)')

    args = parser.parse_args()

    input_image_path = args.input
    if args.output:
        output_image_path = args.output
    else:
        # Generate output path if not provided
        output_image_path = os.path.splitext(input_image_path)[0] + '.png'

    # Perform the conversion
    convert_pgm_to_png(input_image_path, output_image_path)

if __name__ == "__main__":
    main()