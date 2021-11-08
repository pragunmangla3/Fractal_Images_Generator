
#include<fstream>
#include "Bitmap.h"

// #include "BitmapFileHeader.h"
// #include "BitmapInfoHeader.h"



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
    file.write((char *)&m_pPixels,m_width*m_height*3);

    file.close();

    if(!file){  // if we cant close the file -> then we are not even sure that all the data was written into it or not
        return false;
    }


    return true;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue){

}

Bitmap:: ~Bitmap(){

}

}
