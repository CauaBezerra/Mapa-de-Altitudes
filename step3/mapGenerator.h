#include <bits/stdc++.h>
#include "../step1/colorPalet.cpp"

#ifndef MAPGEN
#define MAPGEN

class Map{
    std::vector <std::vector<int>> map;
    int columns;
    int lines;

    public:

    Map(int c, int l);

    int getColumns();

    int getLines();

    int getHeight(int c, int l);

    void createRandom(int min, int max, int var);

    void setMap(std::string archive);

    void createMap(std::string archive);

    void dimondSquare(int px1, int py1, int px2, int py2, int px3, int py3, int px4, int py4, bool square, int max, int min, int var);

};

#endif