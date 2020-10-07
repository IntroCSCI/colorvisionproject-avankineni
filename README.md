# !!!Colorblindness Simulation!!!

## Description

!!!My program is designed to simulate what a colorblind person might see when given an image. The program will take the image based on what type of colorblindness the user chooses and the image will be morphed to simulate that colorblindness.!!!

## Developer

!!!Ankit Vankineni!!!

## Example

To run the program, give the following commands:

```
g++ --std=c++11 main.cpp -o cvp
./cvp
```

Here is an example of the program running:

```
!!!Please enter the file name: dragon.exe
What type of colorblind do you want simulated?
Protanopia 
Deuteranomaly 
Tritanopia
Tritanopia!!!
```

## C++ Guide

### Variables and Data Types

!!!My program contains five variables and four different variable types. I use `Bitmap` to store the image by taking in the file and reading over it; furthermore, I use two `strings` to first get the name of the file and second to get the input of what colorblindness they want to simulate. I also have a `vector` veriable to store the 2D array of pixels and each pixel is stored in a variable called `Pixel` to change the values of each individual pixel.!!!

### Input and Output

!!!The first output and input asks the user for the file name that they want to use to be able disply the image. The second output and input asks the user for which type of colorblindness they want to simulate and based on what they enter, different colors are changed within the image.!!!

### Decisions

!!!The first decision used in my program is used to check if the file that the user input has the required image format based on what is coded inside the function `isImage()`. My next conditions are used to change RGB values based on what the user input for the variable called `colorblind` !!!

### Iteration

!!!My progam uses two `for loops` to fill the contents of a 2D `array`. The first for loop gets the row of the `array` and the second for loop gets the columns. Together, every single pixel is able to be changed.!!!

### File Input and Output

!!!File input and output is used in my program to take in the file the user inputs and validates it through a `if` statement to check if the file contains a valid image. The image file is then changed based on what the user inputs and then is saved at the end of the program.!!!