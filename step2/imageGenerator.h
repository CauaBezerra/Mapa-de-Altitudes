#ifndef IMAGE_GEN
#define IMAGE_GEN
#include "../step1/colorPalet.cpp"
#include <fstream>

class Image{
    int lines;
    int currentLine;
    int columns;
    int currentColumn;
    Pixel **img;

    public:
    Image(int c, int l){
        
    }
    Pixel checkPixel(int c, int l){
        
    }
    void setPixel(Pixel p, int c, int l){
        
    }
    void setImage(std::string link){

    }
    void createImage(){
       
    }
    ~Image(){
        delete img;
    }
};

#endif