#include <iostream>
#include "libraries/bitmap.h"
using namespace std;
#include <cmath>

string file();

string colorblindType();

bool isQuit();

void applyRGBFilter(vector < vector <Pixel> > &, string);

bool check(string);


int main()
{
  Bitmap image;
  string fileName;
  vector < vector <Pixel> > bmp;
  string colorblind;

  fileName = file();

  image.open(fileName);

// Checking if the image is valid or not

  bool validBmp = image.isImage();

  if(validBmp == true) 
  {

  do {

    colorblind = colorblindType();

    while(check(colorblind) == false)
    {
      cout << "\nError: Please enter one of the listed colorblind types.\n" << endl;
      colorblind = colorblindType();
    }

// Initializing the 2D vector to the values that the image gives

    bmp = image.toPixelMatrix();

    applyRGBFilter(bmp, colorblind);

  } while(isQuit() == true);

    image.fromPixelMatrix(bmp);

    image.save(fileName);
  }
  return 0;
}


string file() 
{
  string fileName;
  cout << "Please enter the file name: ";
  cin >> fileName;
  return fileName;
}

string colorblindType() 
{
  string colorblind;
  cout << "What type of colorblind do you want to simulate?: \nProtanopia \nDeuteranomaly \nTritanopia" << endl;
  cin >> colorblind;
  return colorblind;
}

bool isQuit()
{
  char quit;
  cout << "Would you like to alter your answer? y or n" << endl;
  cin >> quit;
  if(quit == 'y') {
    return true;
  }
    return false;
}

bool check(string correctType)
{
  while((correctType == "Protanopia") || (correctType == "Deuteranomaly") || (correctType == "Tritanopia"))
  {
    return true;
  }
  return false;
}

void applyRGBFilter(vector < vector <Pixel> > &bmp, string colorblind)
{
      Pixel rgb;

// Using the for loops to change values in the 2D vector
     
      for(int i = 0; i < bmp.size(); i++)
    {
      for(int j = 0; j < bmp[0].size(); j++) 
      {

        // Setting bmp[i][j] to rgb for conveience of simplification

        rgb = bmp[i][j];

// Using the RGB formuals to insert values into each pixel

    if(colorblind == "Protanopia")
    {
      rgb.red = ceil((rgb.green * .43333) + (rgb.red * .56667));
      rgb.green = ceil((rgb.green * .44167) + (rgb.red * .55833));
      rgb.blue = ceil((rgb.green * .24167) + (rgb.blue * .75833));
    }
    else if(colorblind == "Deuteranomaly")
    {
      rgb.red = ceil((rgb.green * .20) + (rgb.red * .80));
      rgb.green = ceil((rgb.green * .74167) + (rgb.red * .25833));
      rgb.blue = ceil((rgb.green * .14167) + (rgb.blue * .85833));
    }
    else if(colorblind == "Tritanopia")
    {
      rgb.blue = ceil((rgb.green * .475) + (rgb.blue * .525));
      rgb.green = ceil((rgb.green * .43333) + (rgb.blue * .56667));
      rgb.red = ceil((rgb.green * .05) + (rgb.red * .95));
    }

      bmp[i][j] = rgb;

      }
    }
}