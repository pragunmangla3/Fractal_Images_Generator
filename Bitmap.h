#ifndef BITMAP_H_
#define BITMAP_H_

#include<string>

using namespace std;

namespace caveofprogramming{

class Bitmap{
private:
    int m_width {0}; // just some private variables to use later
    int m_height {0}; // just some private variables to use later

public:
    Bitmap(int width, int height);
    // return true if write succeeds and false it doesn't
    bool write(string filename); // you create a bitmap, you set pixels in it and then at the end you write it using this method to a specific file - filename. Bool is used to catch error, maybe if you dont have permission to write on the file
    virtual ~Bitmap();
};


}


#endif