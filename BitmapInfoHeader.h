

#pragma once

#include<cstdint>
using namespace std;


#pragma pack(2)  
 
namespace coveofprogramming{

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

//#pragma pack(pop)

}


