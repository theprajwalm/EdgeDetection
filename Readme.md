Code that converts png/jpg/... <-> pgm and thus lets you run Project 2 on regular image files.


### Running edge detection on an image file
- unzip to directory project-2-...
(all the code in the zip file should be in a directory at the same level as test, scr, ...)

- set permissions
sudo chmod +x process_image.sh

- Execute with image file path as argument:
./process_image.sh <name>.png

output will be a file with the <name>_edge.png


possibly you'd have to install the python library pillow first.

### Converting a pgm -> png

python3 convert_pgm_to_image.py <name>.pgm


### Converting a png -> pgm

python3 convert_img_to_pgm.py <name>.png
