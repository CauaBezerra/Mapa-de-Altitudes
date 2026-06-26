#include "./mapGenerator.h"

Map::Map(int l, int c, int mx, int mn){
    columns = c;
    lines = l;
    max = mx;
    min = mn;
    
    for(int i = 0; i < lines; i++){
        std::vector <int> line;
        for(int j = 0; j < columns; j++){
            line.push_back(0);
        }
        mapH.push_back(line);
    }
}
int Map::getColumns(){
    return columns;
}
int Map::getLines(){
    return lines;
}
int Map::getHeight(int l, int c){
    return mapH[l][c];
}
void Map::createRandom(int var){
    srand(time(0));
    mapH[0][0] = (rand() % (max - min + 1)) + min;
    mapH[0][columns-1] = (rand() % (max - min + 1)) + min;
    mapH[lines-1][0] = (rand() % (max - min + 1)) + min;
    mapH[lines-1][columns-1] = (rand() % (max - min + 1)) + min;
    diamondSquare(0, 0, 0, columns-1, lines-1, 0, lines-1, columns-1, var);
}
void Map::setHeightMap(std::string archive){
    std::ifstream file(archive);
    file >> lines;
    file >> columns;
    for(int i = 0; i < lines; i++){
        std::vector <int> line;
        for(int j = 0; j < columns; j++){
            file >> mapH[i][j];
        }
    }
}
void Map::createHeightMap(std::string archive){
    std::ofstream file(archive);
    file << lines << " " << columns << std::endl;
    for(int i = 0; i < lines; i++){
        for(int j = 0; j < columns; j++){
            file << mapH[i][j] << " ";
        }
        file << std::endl;
    }
}

void Map::diamondSquare(int l1, int c1, int l2, int c2, int l3, int c3, int l4, int c4, int var){
    bool stop = true;
    int medl = (l3 - l1)/2 + l1;
    int medc = (c2 - c1)/2 + c1;
    int medh = 0;
    if(mapH[medl][medc] == 0){
        int medh = (mapH[l1][c1] + mapH[l2][c2] + mapH[l3][c3] + mapH[l4][c4])/4;
        mapH[medl][medc] = (2*(rand()%(var+1)))+(medh-var);
        if(mapH[medl][medc] < min){
            mapH[medl][medc] = min;
        }else if(mapH[medl][medc] > max){
            mapH[medl][medc] = max;
        }
        stop = false;
    }
    if(mapH[medl][c1] == 0){
        if(c1 == 0){
            medh = (mapH[l1][c1] + mapH[medl][medc] + mapH[l3][c3])/3;
        }else{
            medh = (mapH[medl][medc-(c3-c1)] + mapH[l1][c1] + mapH[medl][medc] + mapH[l3][c3])/4;
        }
        mapH[medl][c1] = (2*(rand()%(var+1)))+(medh-var);
        if(mapH[medl][c1] < min){
            mapH[medl][c1] = min;
        }else if(mapH[medl][c1] > max){
            mapH[medl][c1] = max;
        }
        stop = false;
    }
    if(mapH[l1][medc] == 0){
        if(l1 == 0){
            medh = (mapH[l1][c1] + mapH[l2][c2] + mapH[medl][medc])/3;
        }else{
            medh = (mapH[l1][c1] + mapH[medl-(l2-l1)][medc] + mapH[l2][c2] + mapH[medl][medc])/4;
        }
        mapH[l1][medc] = (2*(rand()%(var+1)))+(medh-var);
        if(mapH[l1][medc] < min){
            mapH[l1][medc] = min;
        }else if(mapH[l1][medc] > max){
            mapH[l1][medc] = max;
        }
        stop = false;
    }
    if(mapH[medl][c2] == 0){
        if(c4 == columns-1){
            medh = (mapH[medl][medc] + mapH[l2][c2] + mapH[l4][c4])/3;
        }else{
            medh = (mapH[medl][medc] + mapH[l2][c2] + mapH[medl][medc+(c4-c1)] + mapH[l4][c4])/4;
        }
        mapH[medl][c2] = (2*(rand()%(var+1)))+(medh-var);
        if(mapH[medl][c2] < min){
            mapH[medl][c2] = min;
        }else if(mapH[medl][c2] > max){
            mapH[medl][c2] = max;
        }
        stop = false;
    }
    if(mapH[l3][medc] == 0){
        if(l4 == lines-1){
            medh = (mapH[l3][c3] + mapH[medl][medc] + mapH[l4][c4])/3;
        }else{
            medh = (mapH[l3][c3] + mapH[medl][medc] + mapH[l4][c4] + mapH[medl+(l2-l1)][medc])/4;
        }
        mapH[l3][medc] = (2*(rand()%(var+1)))+(medh-var);
        if(mapH[l3][medc] < min){
            mapH[l3][medc] = min;
        }else if(mapH[l3][medc] > max){
            mapH[l3][medc] = max;
        }
        stop = false;
    }
    if(!(stop)){
        diamondSquare(l1, c1, l1, medc, medl, c1, medl, medc, var);
        diamondSquare(l2, medc, l2, c2, medl, medc, medl, c2, var);
        diamondSquare(medl, c3, medl, medc, l3, c3, l3, medc, var);
        diamondSquare(medl, medc, medl, c4, l4, medc, l4, c4, var);
    }
}
