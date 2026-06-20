#include "imageGenerator.h"
#include <bits/stdc++.h>

Image::Image(int c, int l){
    lines = l;
    columns = c;
    img = new Pixel[columns*lines];
}
int Image::getColumns(){
    return columns;
}
int Image::getLines(){
    return lines;
}
Pixel Image::checkPixel(int c, int l){
    return img[c + l*columns];
}
void Image::setPixel(Pixel p, int c, int l){
    img[c + l*columns] = p;
}
void Image::setImage(std::string archive){
    std::ifstream file(archive);
    std::string buffer;
    file >> buffer;
    buffer = "";
    //tipo de imagem
    delete img;
    file >> columns >> lines;
    img = new Pixel[columns*lines];
    file >> buffer;
    buffer = "";
    //limite hexadecimal
    for(int j = 0; j < columns*lines; j++){
        int r, g, b = 0;
        file >> r >> g >> b;
        img[j].changeRed(r);
        img[j].changeGreen(g);
        img[j].changeBlue(b);
    }
    file.close();
}
void Image::createImage(std::string archive){
    std::ofstream file(archive, std::ios::out);
    file << "P3" << std::endl;
    file << columns << " " << lines << std::endl;
    file << "255" << std::endl;
    for(int i = 0; i < columns*lines; i++){
        file << img[i].getRed() << " " << img[i].getGreen() << " " << img[i].getBlue() << std::endl;
    }
    file.close();
}
Image::~Image(){
    delete img;
}