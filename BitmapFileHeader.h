
#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include<cstdint> // making int 32 bit or 4 bytes explicitly

using namespace std;

#pragma pack(2) // to get rid of the padding in memory between the struck elements and have 2 byte boundaries 
// In C++, if we have stuct like this , it will align data with padding in the way thats most efficient and we cant allow that here

namespace coveofprogramming{

struct BitmapFileHeader{
    char header[2] {'B', 'M'};
    int32_t filesize;  // since we are picky and need 32 bit
    int32_t reserved{0}; // reserved is is not used
    int32_t dataOffset; // how long into the file, actual data actually begins

};

}

#endif