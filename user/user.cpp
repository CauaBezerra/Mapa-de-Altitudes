#include "../step4/mapImage.cpp"

int main(){
    std::cout<<"Certify yourself that this is being run whithin the user folder!"<<std::endl;
    std::cout<<"Copy the palet file into user folder"<<std::endl;
    
    std::cout<<"Insert the name of the palet file (it must not contain spaces):"<<std::endl;
    std::string paletName;
    std::cin>>paletName;
    paletName = "./" + paletName;

    std::fstream openTest(paletName);
    if(openTest.is_open()){
        std::cout<<"Insert the name of the output file (it must not contain spacees, and it must have the .ppm ending):"<<std::endl;
        std::string outputName;
        std::cin>>outputName;
        outputName = "./" + outputName;
        
        if(outputName.size()>4 && (outputName[outputName.size()-4] == '.' && outputName[outputName.size()-3] == 'p' && outputName[outputName.size()-2] == 'p' && outputName[outputName.size()-1] == 'm')){
            std::cout<<"Insert the size of the map's side and the color variation per height respectively: (the map's side must be a power of 2^n + 1 and the color variation must be lower than the amount of colors in the palet)"<<std::endl;
            int l, var;
            Palet teste(paletName);
            std::cin>>l>>var;

            if(l < 1 || var >= teste.pixelNum() || var < 1){
                std::cout<<"Error, defied some restriction on inserted numbers" << std::endl;
            }else{
                Map finalMap(l, l, teste.pixelNum());
                finalMap.createMap(paletName, outputName, var);
                std::cout<<"Your map was created in step4 folder in the " << outputName << " file"<<std::endl;
            }
        }else{
            std::cout<<"Error in the output file's typing (not .ppm)" << std::endl;   
        }
    }else{
        std::cout<<"Failed to find the palet file" << std::endl;
    }
    openTest.close();
}