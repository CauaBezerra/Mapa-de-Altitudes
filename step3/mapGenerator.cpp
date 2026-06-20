#include "./mapGenerator.h"

Map::Map(int l, int c){
    columns = c;
    lines = l;
    for(int i = 0; i < lines; i++){
        std::vector <int> line;
        for(int j = 0; j < columns; j++){
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
int Map::getHeight(int l, int c){
    return map[l][c];
}
void Map::createRandom(int min, int max, int var){
    srand(time(0));
    map[0][0] = (rand() % (max - min + 1)) + min;
    map[0][columns-1] = (rand() % (max - min + 1)) + min;
    map[lines-1][0] = (rand() % (max - min + 1)) + min;
    map[lines-1][columns-1] = (rand() % (max - min + 1)) + min;
    diamondSquare(0, 0, 0, columns-1, lines-1, 0, lines-1, columns-1, max, min, var);
}
void Map::setMap(std::string archive){
    std::ifstream file(archive);
    file >> lines;
    file >> columns;
    for(int i = 0; i < lines; i++){
        std::vector <int> line;
        for(int j = 0; j < columns; j++){
            file >> map[i][j];
        }
    }
}
void Map::createMap(std::string archive){
    std::ofstream file(archive);
    for(int i = 0; i < lines; i++){
        for(int j = 0; j < columns; j++){
            file << map[i][j] << " ";
        }
        file << std::endl;
    }
}

void Map::diamondSquare(int l1, int c1, int l2, int c2, int l3, int c3, int l4, int c4, int max, int min, int var){
    bool stop = true;
    int medl = (l3 - l1)/2 + l1;
    int medc = (c2 - c1)/2 + c1;
    int medh = 0;
    if(map[medl][medc] == 0){
        int medh = (map[l1][c1] + map[l2][c2] + map[l3][c3] + map[l4][c4])/4;
        map[medl][medc] = (rand()%(2*var+1))+(medh-var);
        if(map[medl][medc] < min){
            map[medl][medc] = min;
        }else if(map[medl][medc] > max){
            map[medl][medc] = max;
        }
        stop = false;
    }
    if(map[medl][c1] == 0){
        if(c1 == 0){
            medh = (map[l1][c1] + map[medl][medc] + map[l3][c3])/3;
        }else{
            medh = (map[medl][medc-(c3-c1)] + map[l1][c1] + map[medl][medc] + map[l3][c3])/4;
        }
        map[medl][c1] = (rand()%(2*var+1))+(medh-var);
        if(map[medl][c1] < min){
            map[medl][c1] = min;
        }else if(map[c1][medc] > max){
            map[medl][c1] = max;
        }
        stop = false;
    }
    if(map[l1][medc] == 0){
        if(l1 == 0){
            medh = (map[l1][c1] + map[l2][c2] + map[medl][medc])/3;
        }else{
            medh = (map[l1][c1] + map[medl-(l2-l1)][medc] + map[l2][c2] + map[medl][medc])/4;
        }
        map[l1][medc] = (rand()%(2*var+1))+(medh-var);
        if(map[l1][medc] < min){
            map[l1][medc] = min;
        }else if(map[l1][medc] > max){
            map[l1][medc] = max;
        }
        stop = false;
    }
    if(map[medl][c2] == 0){
        if(c4 == columns-1){
            medh = (map[medl][medc] + map[l2][c2] + map[l4][c4])/3;
        }else{
            medh = (map[medl][medc] + map[l2][c2] + map[medl][medc+(c4-c1)] + map[l4][c4])/4;
        }
        map[medl][c2] = (rand()%(2*var+1))+(medh-var);
        if(map[medl][c2] < min){
            map[medl][c2] = min;
        }else if(map[c2][medc] > max){
            map[medl][c2] = max;
        }
        stop = false;
    }
    if(map[l3][medc] == 0){
        if(l4 == lines-1){
            medh = (map[l3][c3] + map[medl][medc] + map[l4][c4])/3;
        }else{
            medh = (map[l3][c3] + map[medl][medc] + map[l4][c4] + map[medl+(l2-l1)][medc])/4;
        }
        map[l3][medc] = (rand()%(2*var+1))+(medh-var);
        if(map[l3][medc] < min){
            map[l3][medc] = min;
        }else if(map[l3][medc] > max){
            map[l3][medc] = max;
        }
        stop = false;
    }
    if(!stop){
        diamondSquare(l1, c1, l1, medc, medl, c1, medl, medc, max, min, var);
        diamondSquare(l2, medc, l2, c2, medl, medc, medl, c2, max, min, var);
        diamondSquare(medl, c3, medl, medc, l3, c3, l3, medc, max, min, var);
        diamondSquare(medl, medc, medl, c4, l4, medc, c4, c4, max, min, var);
    }
}
