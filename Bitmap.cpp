
#include<fstream>
#include "Bitmap.h"



using namespace caveofprogramming;
using namespace std;

namespace caveofprogramming{

// m_pPixels is the pointer to whole block of memory -> for the whole image (or screen), including all 3 colors
Bitmap::Bitmap(int width, int height): m_width(width), m_height(height), m_pPixels(new uint8_t[width*height*3] {}) {
    
}

bool Bitmap::write(string filename){
    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;

    fileHeader.filesize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) +m_width*m_height*3;
    fileHeader.dataOffset  = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);// distance from the begining of file to where data actually start
    
    infoHeader.width = m_width;
    infoHeader.height = m_height;
    
    ofstream file;

    file.open(filename, ios::out|ios:: binary);

    if(!file){  // if we cant open file
        return false;
    }

    file.write((char *)&fileHeader,sizeof(fileHeader)); // file.write expect a char* pointer and number of bytes to write
    file.write((char *)&infoHeader,sizeof(infoHeader));
    file.write((char *)m_pPixels.get(),m_width*m_height*3);

    file.close();

    if(!file){  // if we cant close the file -> then we are not even sure that all the data was written into it or not
        return false;
    }


    return true;
}




void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue){
  // In bitmap, y is 0 at bottom and increases to top, whereas x is 0 at left and max at right

 uint8_t *pPixel = m_pPixels.get();           // pointer that points to memory block at x and y coordinate (after moving it in the next line)

 pPixel += (y*3)*m_width + (x*3);             // y*m_width is no. of pixel or number of byte, if each pixel is 1 byte -> all the row before the one in focus, then we move forward by x columns. 3 colors, so 3*

 // stored in reverse order -> blue,green and red instead of red green and blue-> due to little endian format  
 pPixel[0] = blue;
 pPixel[1] = green;
 pPixel[2] = red;


}

Bitmap:: ~Bitmap(){

}

}
