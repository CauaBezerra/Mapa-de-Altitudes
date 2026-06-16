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
    std::ifstream file(link, std::ios::in);
    std::string buffer;
    std::getline(file, buffer);
    //tipo de imagem
    std::getline(file, buffer);
    columns = std::stoi(buffer.substr(0, 0));
    lines = std::stoi(buffer.substr(2, 2));
    std::getline(file, buffer);
    //limite hexadecimal
    std::getline(file, buffer);
    int j = 0;
    std::string numS;
    for(int i = 0; i < buffer.size(); i++){
        int rgb = 0;
        if(i != 0 && (buffer[i] == ' ' && buffer[i-1])){
            
        }else if(buffer[i] == ' '){
            if(rgb == 0){
                img[j]->changeRed(std::stoi(numS));
                numS = "";
                rgb++;
            }else if(rgb == 1){
                img[j]->changeGreen(std::stoi(numS));
                numS = "";
                rgb++;
            }else{
                img[j]->changeBlue(std::stoi(numS));
                numS = "";
                rgb = 0;
            }
        }else{
            numS += buffer[i];
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
        file << img[i]->getRed() << " " << img[i]->getGreen() << " " << img[i]->getBlue() << "  ";
    }
    file.close();
}
Image::~Image(){
    for(int i = 0; i < columns*lines; i++){
        delete img[i];
    }
    delete img;
}