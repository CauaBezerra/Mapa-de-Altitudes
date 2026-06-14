#include "pixel.h"
#ifndef PALET
#define PALET
#include <bits/stdc++.h>


class Palet{
    private:
    std::vector<Pixel> paletVector;
    
    public:
    Palet ();

    Palet(std::string archive);

    void addPixel( Pixel newPixel);

    int pixelNum();

    Pixel getPixel(unsigned int i);
};



#endif