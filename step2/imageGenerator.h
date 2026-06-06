#include "../step1/pixel.h"
#include <fstream>

class Image{
    int lines;
    int currentLine;
    int columns;
    int currentColumn;
    int *img;

    public:
    Image(int c, int l){
        lines = l;
        columns = c;
        Pixel pixels = new Pixel[columns*lines];
        img = pixels;
    }
    Pixel checkPixel(int c, int l){
        return img[c + l*columns];
    }
    void setPixel(Pixel p, int c, int l){
        img[c + l*columns] = p;
    }
    void createImage(){
        std::ofstream file("../imageOutput.PPM", std::ios::out);
        file << "P3" << std::endl;
        file << columns << " " << lines << std::endl;
        file << "255" << std::endl;
        for(int i = 0; i < columns*lines; i++){
            file << img[i];
        }
    }
    ~Image(){
        delete img;
    }
};