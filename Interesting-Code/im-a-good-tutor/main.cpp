#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

void function();

int main() {
    int ward = -1;
    ward = ward + 1;

    std::vector<int> myData = {1,5,467,775346,6543,5465788,32,573,7,9,4,2,69,0};

    std::sort(myData.begin(),myData.end(),std::less<>());

    std::fstream file;
    if(file.fail()){
        std::cout<<"Hello!";
        exit(1);
    }
    file.open("myFile.txt",std::ios::out);

    std::string skill = "Hello this is a string of data being stored inside skill";

    for(int i = 0; i < myData.size(); i++){
        file<<myData[i]<<std::endl;
    }

    function();
    file.close();
    exit(0);
}

void function(){
    std::cout<<"Hello!"<<std::endl;
}