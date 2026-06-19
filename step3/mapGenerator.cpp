#include "./mapGenerator.h"

Map::Map(int c, int l){
    columns = c;
    lines = l;
    for(int i = 0; i < columns; i++){
        std::vector <int> line;
        for(int j = 0; j < lines; j++){
            line.push_back(0);
        }
        map.push_back(line);
    }
}
int Map::getColumns(){
    return columns;
}
int Map::getLines(){
    return lines;
}
int Map::getHeight(int c, int l){
    return map[c][l];
}
void Map::createRandom(int min, int max, int var){
    srand(time(0));
    map[0][0] = (rand() % (max - min + 1)) + min;
    map[0][columns-1] = (rand() % (max - min + 1)) + min;
    map[lines-1][0] = (rand() % (max - min + 1)) + min;
    map[lines-1][columns-1] = (rand() % (max - min + 1)) + min;
}
void Map::setMap(std::string archive){

}
void Map::createMap(std::string archive){

}

void Map::dimondSquare(int px1, int py1, int px2, int py2, int px3, int py3, int px4, int py4, bool square, int max, int min, int var){
    if(square){
        int medx = px2;
        int medy = py1;
        int medh;
        if(px1 < 0){
            medh = (map[px2][py2] + map[px3][py3] + map[px4][py4])/3;
        }else if(px2 < 0){
            medh = (map[px1][py1] + map[px3][py3] + map[px4][py4])/3;
        }else if(px3 < 0){
            medh = (map[px1][py1] + map[px2][py2] + map[px4][py4])/3;
        }else if(px4 < 0){
            medh = (map[px1][py1] + map[px2][py2] + map[px3][py3])/3;
        }else{
            medh = (map[px1][py1] + map[px2][py2] + map[px3][py3] + map[px4][py4])/4;
        }
        if(map[medx][medy] == 0){
            map[medx][medy] = (rand()%(2*var+1))+(medh-var);
            if(map[medx][medy] < min){
                map[medx][medy] = min;
            }else if(map[medx][medy] > max){
                map[medx][medy] = max;
            }
            if(px1 < 0){
                dimondSquare(px2, py2, px3, py2, medx, medy, px3, py3, true, max, min, var);
            }
        }
    }else{
        int medx = (px2 - px1)/2 + px1;
        int medy = (py3 - py1)/2 + py1;
        int medh = (map[px1][py1] + map[px2][py2] + map[px3][py3] + map[px4][py4])/4;
        if(map[medx][medy] == 0){
            map[medx][medy] = (rand()%(2*var+1))+(medh-var);
            if(map[medx][medy] < min){
                map[medx][medy] = min;
            }else if(map[medx][medy] > max){
                map[medx][medy] = max;
            }
            if(px1 == 0){
                dimondSquare(-1, -1, px1, py1, medx, medy, px3, py3, true, max, min, var);
            }else{
                dimondSquare(medx-(px2-px1), medy, px1, py1, medx, medy, px3, py3, true, max, min, var);
            }
            if(py1 == 0){
                dimondSquare(px1, py1, -1, -1, px2, py2, medx, medy, true, max, min, var);
            }else{
                dimondSquare(px1, py1, medx, medy-(py3-py1), px2, py2, medx, medy, true, max, min, var);
            }
            if(px1 == columns-1){
                dimondSquare(medx, medy, px2, py2, -1, -1, px4, py4, true, max, min, var);
            }else{
                dimondSquare(medx, medy, px2, py2, medx+(px2-px1), medy, px4, py4, true, max, min, var);
            }
            if(py1 == lines-1){
                dimondSquare(px2, py2, medx, medy, px4, py4, -1, -1, true, max, min, var);
            }else{
                dimondSquare(px2, py2, medx, medy, px4, py4, medx, medy-(py3-py1), true, max, min, var);
            }
        }
    }
}