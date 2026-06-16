#include "imageGenerator.h"
#include <bits/stdc++.h>

Image::Image(int c, int l){
    lines = l;
    columns = c;
    img = new Pixel*[columns*lines];
    for(int i = 0; i < columns*lines; i++){
        img[i] = new Pixel(0, 0, 0);
    }
}
int Image::getColumns(){
    return columns;
}
int Image::getLines(){
    return lines;     
}
Pixel Image::checkPixel(int c, int l){
    return *img[c + l*columns];
}
void Image::setPixel(Pixel p, int c, int l){
    *img[c + l*columns] = p;
}
void Image::setImage(std::string link){
    std::ifstream file(link);
    std::string buffer;
    file >> buffer;
    buffer = "";
    //tipo de imagem
    file >> columns >> lines;
    file >> buffer;
    buffer = "";
    //limite hexadecimal
    int rgb = 0;
    for(int j = 0; j < columns*lines; j++){
        int numS = 0;
        file >> numS;
        if(rgb == 0){
            img[j]->changeRed(numS);
            rgb++;
        }else if(rgb == 1){
            img[j]->changeGreen(numS);
            rgb++;
        }else{
            img[j]->changeBlue(numS);
            rgb = 0;
        }
    }
    file.close();
}
void Image::createImage(std::string archive){
    std::ofstream file(archive, std::ios::out);
    file << "P3" << std::endl;
    file << columns << " " << lines << std::endl;
    file << "255" << std::endl;
    for(int i = 0; i < columns*lines; i++){
        file << img[i]->getRed() << " " << img[i]->getGreen() << " " << img[i]->getBlue() << std::endl;
    }
    file.close();
}
Image::~Image(){
    for(int i = 0; i < columns*lines; i++){
        delete img[i];
    }
    delete img;
}