#include "imageGenerator.h"

Image::Image(int c, int l){
    lines = l;
    columns = c;
    img = new Pixel*[columns*lines];
    for(int i = 0; i < columns*lines; i++){
        img[i] = new Pixel(0, 0, 0);
    }
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
    std::getline(file, buffer);
    std::getline(file, buffer);
    std::getline(file, buffer);
    file.close();
}
void Image::createImage(){
    std::ofstream file("./imageOutput.ppm", std::ios::out);
    file << "P3" << std::endl;
    file << columns << " " << lines << std::endl;
    file << "255" << std::endl;
    for(int i = 0; i < columns*lines; i++){
        file << img[i];
    }
    file.close();
}