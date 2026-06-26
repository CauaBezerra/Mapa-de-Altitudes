#include "./step4/mapImage.cpp"

int main(){
    std::cout<<"Type the size of the map's side, max height and min height (min height must be higher than 0) respectively:"<<std::endl;
    int l, mx, mn;
    if(mn<0){
        mn = 1;
        std::cout<<"As you wrote min wrong we (not dumb people) set it to 1"<<std::endl;
    }
    std::cin>>l>>mx>>mn;
    
    Map finalMap(l, l, mx, mn);
    finalMap.createMap("./step4/paletInPut.txt", "./step4/mapOutPut.ppm");
    finalMap.createHeightMap("./mapH.txt");
    std::cout<<"Your map was created in step4 folder in mapOutPut.ppm file"<<std::endl;
}