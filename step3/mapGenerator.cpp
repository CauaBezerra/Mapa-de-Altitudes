#include "./mapGenerator.h"

void dimondSquare(int p1, int p2, int p3, int p4, bool square);

Map::Map(int c, int l){
    columns = c;
    lines = l;
    for(int i = 0; i < lines*columns; i++){
        map.push_back(0);
    }
}
int Map::getColumns(){
    return columns;
}
int Map::getLines(){
    return lines;
}
int Map::getHeight(int c, int l){

}
void Map::createRandom(int min, int max){
    srand(time(0));
    map[0] = (rand() % (max - min + 1)) + min;
    map[columns-1] = (rand() % (max - min + 1)) + min;
    map[(lines-1)*columns] = (rand() % (max - min + 1)) + min;
    map[lines*columns-1] = (rand() % (max - min + 1)) + min;
}
void Map::setMap(std::string archive){

}
void Map::createMap(std::string archive){

}

void dimondSquare(int p1, int p2, int p3, int p4, bool square){

}