#include "../step2/imageGenerator.cpp"
#include "../step3/mapGenerator.cpp"

void Map::createMap(std::string paletArchive, std::string outPutArchive){
    Palet palet(paletArchive);
    int colorVar = (max-min)/palet.pixelNum();
    Image map(columns, lines);
    for(int i = 0; i < lines; i++){
        for(int j = 0; j < columns; j++){
            map.setPixel(palet.getPixel(mapH[i][j]/colorVar), j, i);
        }
    }

    for(int i = 1; i < lines; i++){
        for(int j = 1; j < columns; j++){
            if(mapH[i-1][j-1] > mapH[i][j]){
                Pixel shadow;
                shadow.changeRed((map.checkPixel(j, i).getRed())/2);
                shadow.changeGreen((map.checkPixel(j, i).getGreen())/2);
                shadow.changeBlue((map.checkPixel(j, i).getBlue())/2);
                map.setPixel(shadow, j, i);
            }
        }
    }

    map.createImage(outPutArchive);
}