#include "../step4/mapImage.cpp"

int main(){
    std::cout<<"Certify yourself that this is being run whithin the user folder!"<<std::endl;
    std::cout<<"Copy the palet file into user folder"<<std::endl;
    
    std::cout<<"Insert the name of the palet file (it must not contain spacees):"<<std::endl;
    std::string paletName;
    std::cin>>paletName;
    paletName = "./" + paletName;

    std::cout<<"Insert the name of the output file (it must not contain spacees, and it must have the .ppm ending):"<<std::endl;
    std::string outputName;
    std::cin>>outputName;
    outputName = "./" + outputName;

    std::cout<<"Insert the size of the map's side, max height and min height (min height must be higher than 0 and the diference of max-min must be higher than the number of colors in your palet) respectively:"<<std::endl;
    int l, mx, mn;
    if(mn<0){
        mn = 1;
        //std::cout<<"As you wrote min wrong we (not dumb people) set it to 1"<<std::endl;
    }
    std::cin>>l>>mx>>mn;
    
    Map finalMap(l, l, mx, mn);
    finalMap.createMap(paletName, outputName);
    finalMap.createHeightMap("./mapH.txt");
    std::cout<<"Your map was created in step4 folder in the " << outputName << " file"<<std::endl;
}