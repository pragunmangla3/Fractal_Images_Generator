#pragma once
#include"zoom.h"

#include<vector>
#include<utility>

using namespace std;

namespace caveofprogramming{

class ZoomList{
private:

    double m_xCenter{0};
    double m_yCenter{0};
    double m_scale{1.0};

    int m_width{0};
    int m_height{0};
    vector<Zoom> zooms;

public:
    ZoomList(int width, int height);
    void add(const Zoom& zoom);
    pair<double,double> doZoom(int x,int y); // aplies algo to zoom and return zoomed coordinates

};

}