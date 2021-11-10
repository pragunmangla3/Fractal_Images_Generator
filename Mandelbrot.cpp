#include <complex>
#include "Mandelbrot.h"

using namespace std;

namespace caveofprogramming{

Mandelbrot::Mandelbrot(){

}

Mandelbrot::~Mandelbrot(){

}

// to see after how many iterations, number shoots off to infinity
int Mandelbrot::getIterations(double x, double y){
   
   complex<double> z  {0};
   complex<double> c(x,y);

   int iterations {0};
   
   while(iterations<MAX_ITERATIONS){
       z = z*z + c;

      //geting the magnitude of complex number. Normally z is less than 2 (between -1 and +1), but if magnitude breaks 2, then it goes till infinity.
      // if it does not break 2, then we say its part of madelbrot set, the number will remain bounded no matter how many iterations you do
      if(abs(z)>2){
          break;
      }

       iterations++;
   }
   
   
   return iterations;
}


}