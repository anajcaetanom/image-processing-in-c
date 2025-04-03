# 🖼️ PPM Image Processor in C  

## 📌 Overview  

This project, developed by **Ana Júlia Caetano Martins**, is a C application for processing images in the **PPM (Portable Pixmap) format**. The main functionalities include:  

- 🖼️ **Loading** a PPM image.  
- 🎨 **Converting** the image to grayscale.  
- 💾 **Saving** the converted image to a new file.  

## 🚀 How to Run the Program  

### 🔧 Compilation  

1. Open a terminal in the directory containing the source files and the `Makefile`.  
2. Run `make` to compile the program.  
3. The executable `test_image` will be created.  

### ▶️ Execution  

1. Run the program with `./test_image`.  
2. A menu will appear with the following options:  
   - 📂 **Load** a PPM image.  
   - 🎭 **Convert** the image to grayscale.  
   - 💾 **Save** the converted image to a file.  
3. Follow the on-screen instructions to interact with the program.  

## 🛠️ Implementation Details  

- **📝 Memory Allocation**: Uses `calloc` to allocate memory in the heap, ensuring proper initialization and preventing garbage data issues.  
- **🗑️ Memory Deallocation**: Implements the `matrix_deallocation` function to free dynamically allocated memory for the pixel matrix, preventing memory leaks.  
- **🔄 User Interaction**: Allows the user to specify the directory and file name when loading and saving images, providing flexibility in file management.  

## 📁 Project Structure  

- `main.c` – The main file, responsible for user interaction.  
- `image.c` & `image.h` – Implementation and definitions for image processing functions.  
- `Makefile` – Script to automate the compilation process.  

## 🚀 Future Improvements  

- 🖼️ Support for additional image formats beyond PPM.  
- 🌟 Image editing features such as brightness and contrast adjustments.  
- 🖥️ A graphical user interface (GUI) for better user experience.  

---  

📌 *This project was developed as part of the **Data Structures** course during the **2023/2 semester**.*  
