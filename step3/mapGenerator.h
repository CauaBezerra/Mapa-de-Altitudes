#include <bits/stdc++.h>
#include "../step1/colorPalet.cpp"

#ifndef MAPGEN
#define MAPGEN

class Map{
    std::vector <int> map;
    int columns;
    int lines;

    public:
    Map(int c, int l);

    int getColumns();

    int getLines();

    int getHeight(int c, int l);

    void createRandom(int min, int max);

    void setMap(std::string archive);

    void createMap(std::string archive);

};

#endif