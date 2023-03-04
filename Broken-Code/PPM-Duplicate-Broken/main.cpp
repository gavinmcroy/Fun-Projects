#include <iostream>
#include <fstream>
#include<vector>
#include <cstdlib>
#include "Pixel.h"

int main() {
    std::vector<Pixel> image;
    std::ifstream file;
    std::ofstream outputFile;
    std::string buffer;
    int width = 690/2;
    int height = 461/2;
    file.open("tiger.ppm");

    if(file.fail()){
        exit(1);
    }

    for(int i = 0; i < 3; i++){
        std::string trash;
        getline(file,trash);
        std::cout<<trash<<std::endl;
    }
    std::string r,g,b;
    int counter = 0;

    while(file >> r  >> g >>b/* >> g >> b */){
        char red = r.at(0);
        char green = g.at(0);
        char blue = b.at(0);
        Pixel pixel(red,green,blue);
        image.push_back(pixel);
        counter++;
    }

    outputFile.open("Duplicate.ppm");

    if(outputFile.fail()){
        exit(2);
    }

    outputFile << "P6 " << 690 << " "<<461 << std::endl;
    std::cout<<counter<<std::endl;


    for(auto & i : image){
        outputFile << i.red << i.green<<std::endl << i.blue<<std::endl;
        //outputFile << ;
        //outputFile << i.blue<<std::endl;
    }
    return 0;


}
