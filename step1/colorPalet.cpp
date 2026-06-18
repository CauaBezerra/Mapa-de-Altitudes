#include <bits/stdc++.h>
#include <fstream>

#include "pixel.h"
#include "colorPalet.h"

Pixel::Pixel(){
    Red = 0;
    Blue = 0;
    Green = 0;
};

Pixel::Pixel(unsigned int r, unsigned int g, unsigned int b){
    if(r>255){
        r=255;
    }
    if(b>255){
        b=255;
    }
    if(g>255){
        g=255;
    }
    
    Red = r; 
    Blue = b; 
    Green = g;
}

unsigned int Pixel::getRed (){
    return Red;
}
    
unsigned int Pixel::getBlue(){
    return Blue;
}

unsigned int Pixel::getGreen(){
    return Green;
}

void Pixel::changeRed(unsigned int newR){
    if(newR>255){
        newR=255;
    }
    else{
        Red = newR;
    }
    
};
    
void Pixel::changeBlue(unsigned int newB){
    if(newB>255){
        newB=255;
    }
    else{
        Blue = newB;
    }
};

void Pixel::changeGreen(unsigned int newG){
    if(newG>255){
        newG=255;
    }
    else{
        Green = newG;
    }
};

//Palet 

Palet::Palet(){
    paletVector = {};
};

Palet::Palet(std::string archive){
    std::ifstream file(archive);
    std::string line;
    int r;
    int g;
    int b;
    if(file.is_open()){
        while (std::getline(file , line))
        {
            r = std::stoi(line.substr(1 , 2) , nullptr , 16 );
            g = std::stoi(line.substr(3 , 2) , nullptr , 16 );
            b = std::stoi(line.substr(5 , 2) , nullptr , 16 );

            paletVector.push_back( Pixel(r , g , b) ); 
        }
    }
    else{
        std::cout<<"failed to open file"<<std::endl;
    }
};

void Palet::addPixel( Pixel newPixel){
    paletVector.push_back(newPixel);
};

int Palet::pixelNum(){
    return paletVector.size();
};

Pixel Palet::getPixel(unsigned int i){
    if(i>=paletVector.size()){
        return Pixel(0 , 0 , 0);
    }
    return paletVector[i];
};