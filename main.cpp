#include "./step4/mapImage.cpp"

int main(){
    std::cout<<"Type the number of lines, columns , max height and min height (min height must be higher than 0) respectively:"<<std::endl;
    int c, l, mx, mn;
    if(mn<0){
        mn = 1;
        std::cout<<"As you wrote min wrong we (not dumb people) set it to 1"<<std::endl;
    }
    std::cin>>c>>l>>mx>>mn;
    Map finalMap(l, c, mx, mn);
    finalMap.createMap("./step4/paletInPut.txt", "./step4/mapOutPut.ppm");
    finalMap.createHeightMap("./mapH.txt");
    std::cout<<"Your map was created in step4 folder in mapOutPut.ppm file"<<std::endl;
}