// #ifndef BITMAP_H_
// #define BITMAP_H_

#pragma once

#include<string>
#include<cstdint>
#include<memory> // to use smart pointer.

using namespace std;

namespace caveofprogramming{

#pragma pack(push,2)

struct BitmapFileHeader{
    char header[2] {'B', 'M'};
    int32_t filesize;  // since we are picky and need 32 bit
    int32_t reserved{0}; // reserved is is not used
    int32_t dataOffset; // how long into the file, actual data actually begins

};

#pragma pack(pop)


#pragma pack(push,2)
struct BitmapInfoHeader{
    int32_t headerSize{40};  // represents the total size of this struct. Int32_t -> 4bytes, Int16_t -> takes 2 bytes
    int32_t width; // width of actual bitmap
    int32_t height; // height of actual bitmap
    int16_t planes{1}; // related layer maybe (not sure)
    int16_t bitsPerPixel{24}; // gonna use 1 byte (or 8 bits) for each color. We have 3 colors RGB (red, green and blue)
    int32_t compression{0}; // we are not going to use this, coz it will complicate things
    int32_t dataSize{0}; // We are going to set this later to the size of data that we write
    int32_t horizontalResolution{2400}; // means 2400 bits per pixel
    int32_t verticalResolution{2400}; // means 2400 bits per pixel
    int32_t colors{0}; // not used
    int32_t importantColors{0}; // not used

};

#pragma pack(pop)



class Bitmap{
private:
    int m_width {0}; // just some private variables to use later
    int m_height {0}; // just some private variables to use later

    /*
     We are gonna allocate all the memory we need about each and every pixel on our screen. and we will set pixel in the memory and write it in the file.
    */
    unique_ptr<uint8_t []>m_pPixels{nullptr}; // std::unique_ptr is a smart pointer that owns and manages another object through a pointer and disposes of that object when the unique_ptr goes out of scope.

public:
    Bitmap(int width, int height);

    // return true if write succeeds and false it doesn't
    bool write(string filename); // you create a bitmap, you set pixels in it and then at the end you write it using this method to a specific file - filename. Bool is used to catch error, maybe if you dont have permission to write on the file

    void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue); // set pixels in the bitmap to specified colors (1-255) -> unsigned char -> uint8_t
    virtual ~Bitmap();
};


}


//#endif
