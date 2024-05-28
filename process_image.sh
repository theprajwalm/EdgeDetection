filename_no_extension="${1%.*}"
new_filename="${filename_no_extension}_edges.png"
python3 convert_img_to_pgm_p2.py $1 image.pgm
../bin/edgedetection -T 100 image.pgm
python3 convert_pgm_to_image.py ./out_edges.pgm $new_filename