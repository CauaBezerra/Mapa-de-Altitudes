#include <bits/stdc++.h>
#include "../step1/colorPalet.cpp"

#ifndef MAPGEN
#define MAPGEN

class Map{
    std::vector <std::vector<int>> mapH;
    int columns;
    int lines;
    int max;
    int min;

    public:

    Map(int l, int c, int varh);

    int getColumns();

    int getLines();

    int getHeight(int l, int c);

    void createRandom(int var);

    void setHeightMap(std::string archive);

    void createHeightMap(std::string archive);

    void diamondSquare(int px1, int py1, int px2, int py2, int px3, int py3, int px4, int py4, int var);

    void createMap (std::string paletArchive, std::string outPutArchive, int var);
};

#endif