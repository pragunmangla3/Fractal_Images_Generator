#include<iostream>
#include<cstdint>
#include "Bitmap.h"
#include "Mandelbrot.h"

using namespace std;
using namespace caveofprogramming;
// our program writes fractal image to a bitmap



int main(){

    
    
    int const WIDTH = 800;
    int const HEIGHT = 600;

    Bitmap bitmap(WIDTH,HEIGHT);
    
    // value of xFractal and yFractal ranges  from -1 to +1. Hence we are doing the math

    // double min = 999999;
    // double max = -999999;

    for(int y=0;y<HEIGHT;y++){
        for(int x=0;x<WIDTH;x++){
             
             // the scaling factor 2.0/something should be same for both x and y
             double xFractal = (x- WIDTH/2) * 2.0/HEIGHT;
             double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT;
            
            int iterations = (double)Mandelbrot::getIterations(xFractal,yFractal);
            uint8_t color = (uint8_t)(256* iterations/Mandelbrot::MAX_ITERATIONS);

            color = color*color*color; // since we are using uint8_t, we are gonna end up with max 255 value anyway. So making color more random

            bitmap.setPixel(x,y,color,color,color);


        }
    }


    bitmap.write("test.bmp");

    cout<<"Finished."<<endl;

}

/*
We are gonna allocate all the memory we need about each and every pixel on our screen. and we will set pixel in the memory and write it in the file.

*/