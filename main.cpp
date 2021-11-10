#include<iostream>
#include<cstdint>
#include<math.h>
#include <memory>
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

    // we have not included + 1 (the last entry), since it messes up with the image. (the once inside of mandlebrot set).
    unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{0});

    // for every pixel, we need to store the number of iterations
    unique_ptr<int[]> fractal(new int[WIDTH*HEIGHT]{0});

    for(int y=0;y<HEIGHT;y++){
        for(int x=0;x<WIDTH;x++){
             
            // the scaling factor 2.0/something should be same for both x and y
            double xFractal = (x- WIDTH/2 -200) * 2.0/HEIGHT;
            double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT;
            
            

            int iterations = (double)Mandelbrot::getIterations(xFractal,yFractal);

            // storing like how actual Bitmap is made
            fractal[y*WIDTH+x] = iterations;

             // we have not included + 1 (the last entry), since it messes up with the image. (the once inside of mandlebrot set).
            if(iterations!=Mandelbrot::MAX_ITERATIONS){
                histogram[iterations]++;
            }
            
           
        }
    }


    int total {0};  // storing total no. of iterations (valid iterations -> abs()<2) in the histogram.
    for(int i{0};i<Mandelbrot::MAX_ITERATIONS;i++){
        total += histogram[i];
    }

    for(int y=0;y<HEIGHT;y++){
        for(int x=0;x<WIDTH;x++){
            
            uint8_t red {0};
            uint8_t green {0};
            uint8_t blue {0};

            int iterations = fractal[y*WIDTH+x];

            if(iterations!=Mandelbrot::MAX_ITERATIONS){

            double hue {0.0};// storing all the pixels with less than or equal to current number of iterations, which out color shade will depend upon
            for(int i{0};i<=iterations;i++){
                hue += ((double)histogram[i])/total;
            }
        
            green  = pow(255,hue);
            
            }

            bitmap.setPixel(x,y,red,green,blue);

     
        }
    }

    bitmap.write("test.bmp");

    cout<<"Finished."<<endl;

}

/*
We are gonna allocate all the memory we need about each and every pixel on our screen. and we will set pixel in the memory and write it in the file.

*/