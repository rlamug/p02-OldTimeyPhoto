//Rodolfo Lamug
#include <iostream>
#include <vector>
#include <string>
#include "bitmap.h"

using namespace std;

int main()
{
/*
-Ask user for name of the file (and it must be in bmp)
-If the name of the file is invalid or in incorrect format ask again
-Store the users input if it's correct
-Create the image in greyscale using collumns and rows and alter rgb values
-create new file and save it as oldtimey.bmp
*/
std::string name;
Bitmap image;
vector <vector <Pixel> > bmp;
Pixel rgb;
float red;
float green;
float blue;
float gray;
float grays;

//Put in image file here
do
{
cout << "Enter the name of the image (the image must be in bmp format)" <<endl;
cin>>name;
image.open(name);
}
while (image.isImage() == false);

cout <<name<< " has been succesfully loaded. It has a " <<bmp[0].size()<< " pixel width and a " <<bmp.size()<< " pixel height."<< endl;
bmp = image.toPixelMatrix();

//Convert image to greyscale
for (int row=0; row < bmp.size(); row++)
{
    for (int col=0; col < bmp[0].size(); col++ )
    {
        rgb = bmp[row][col];
        gray = (rgb.red*0.3) + (rgb.green*0.59) + (rgb.blue*0.11);
        grays = gray/3;
        rgb.red = grays;
        rgb.green = grays;
        rgb.blue = grays;
        bmp[row][col] = rgb;
        cout<<"Converting file to grayscale image. This may take a moment."<<endl;
    }
}

//Puts changed image back into matrix and saves it as oldtimey.bmp.
image.fromPixelMatrix(bmp);
image.save("oldtimey.bmp");
cout<<"Image is now in greyscale and named oldtimey.bmp"<<endl;
    return 0;
}
