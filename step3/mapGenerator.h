#include <bits/stdc++.h>
#include "../step1/colorPalet.cpp"

#ifndef MAPGEN
#define MAPGEN

class Map{
    std::vector <std::vector<int>> map;
    int columns;
    int lines;

    public:

    Map(int l, int c);

    int getColumns();

    int getLines();

    int getHeight(int l, int c);

    void createRandom(int min, int max, int var);

    void setMap(std::string archive);

    void createMap(std::string archive);

    void diamondSquare(int px1, int py1, int px2, int py2, int px3, int py3, int px4, int py4, int max, int min, int var);

};

#endif