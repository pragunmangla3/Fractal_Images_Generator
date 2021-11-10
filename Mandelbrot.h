#pragma once

namespace caveofprogramming{

// Mandelbrot algo gives us the right amount of iterations needed to get pixel color
class Mandelbrot{
public:
    static const int MAX_ITERATIONS = 1000; // more iteration means better quality. But its a tradeoff

public:
    Mandelbrot();
    virtual ~Mandelbrot();

    static int getIterations(double x,double y);

};


}