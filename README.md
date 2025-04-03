# Project 1 - Data Structures

## Overview

This project, developed by **Ana Júlia Caetano Martins**, is a C application for processing images in the PPM format. The main functionalities include:

- **Loading** a PPM image.
- **Converting** the image to grayscale.
- **Saving** the converted image to a new file.

## How to Run the Program

1. **Compilation**:
   - Open a terminal in the directory containing the source files and the Makefile.
   - Run `make` to compile the program. This will generate an executable named `test_image`.

2. **Execution**:
   - In the terminal, execute the program with `./test_image`.
   - A menu will appear with the following options:
     - **Load** a PPM image.
     - **Convert** the image to grayscale.
     - **Save** the converted image to a file.
   - Follow the on-screen instructions to interact with the program.

## Implementation Details

- **Memory Allocation**: Uses `calloc` to allocate memory in the heap, ensuring proper initialization and preventing garbage data issues.
- **Memory Deallocation**: Implements the `matrix_deallocation` function to free dynamically allocated memory for the pixel matrix, preventing memory leaks.
- **User Interaction**: The program allows the user to specify the directory and file name when loading and saving images, providing flexibility in file management.

## Project Structure

- `main.c`: The main file, responsible for user interaction.
- `image.c` and `image.h`: Implementation and definitions for image processing functions.
- `Makefile`: Script to automate the compilation process.

## Future Improvements

- Add support for image formats beyond PPM.
- Implement additional image editing features, such as brightness and contrast adjustments.
- Develop a graphical user interface (GUI) for a more user-friendly experience.

---

*This project was developed as part of the Data Structures course during the 2023/2 semester.*
