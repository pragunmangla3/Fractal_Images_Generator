#pragma once

namespace caveofprogramming{

class Zoom{
    public:
    int x {0}; // x coordinate to zoom
    int y {0}; // y coordinate we need to zoom
    double scale{0.0};
    Zoom(int x, int y, double scale) : x{x}, y{y}, scale{scale}{}



};

}