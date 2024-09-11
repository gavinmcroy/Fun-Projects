#include <iostream>
#include <fstream>

void func();

using namespace std;

int main() {
    int x = 0;
//    std::cout<<x;
    const std::string myVar = "Blue is a shitter";
    std::cout << myVar << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << myVar << std::endl;
    }
    std::ofstream myFile;
    myFile.open("better.txt");
    std::ifstream inputFile;
    inputFile.open("file.txt");
    if (!inputFile) {
        std::cerr << "That will not work" << std::endl;
    }
    if (!myFile) {
        std::cerr << "Error" << std::endl;
        exit(1);
    }

    int i = 0;
    while (true) {
        if (i == 20) {
            break;
        }
        myFile << "Hello everyone" << std::endl;
        i++;
    }

    return 0;
}

void func(){
    int x= 0;
}