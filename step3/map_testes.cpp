#include "mapGenerator.cpp"

int main(){
    Map cleiton(5 , 5, 101, 1);
    cleiton.setHeightMap("./step3/map_teste.txt");
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            std::cout << cleiton.getHeight(i, j) << " ";
        }
        std::cout << std::endl;
    }
    cleiton.createRandom(1, 100, 10);
    cleiton.createHeightMap("./step3/map_teste.txt");
}
