#include <iostream>
#include "libraries/bitmap.h"
using namespace std;
#include <cmath>

int main()
{
  Bitmap image;

  string fileName;

  vector < vector <Pixel> > bmp;

  Pixel rgb;

  string colorblind;

  cout << "Please enter the file name: ";

  cin >> fileName;

      cout << "What type of colorblind do you want to simulated?: \nProtanopia \nDeuteranomaly \nTritanopia" << endl;

    cin >> colorblind;

  image.open(fileName);

  bool validBmp = image.isImage();

  if(validBmp == true) 
  {
    
    bmp = image.toPixelMatrix();
    for(int i = 0; i < bmp.size(); i++) {
      for(int j = 0; j < bmp[0].size(); j++) {
    rgb = bmp[i][j];

    if(colorblind == "Protanopia")
    {
      rgb.red = ceil(rgb.red/3);
    }
    else if(colorblind == "Deuteranomaly")
    {
      rgb.green = ceil(rgb.green/3);
    }
    else if(colorblind == "Tritanopia")
    {
      rgb.blue = ceil(rgb.blue/3);
    }

    bmp[i][j] = rgb;
      }
    }
    image.fromPixelMatrix(bmp);

    image.save(fileName);
  }
  return 0;
}