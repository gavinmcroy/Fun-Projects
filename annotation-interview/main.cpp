#include <iostream>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

void myFunction(std::string &fileName);


int main() {
    string val = "coding_qual_input.txt";
    myFunction(val);
    return 0;
}

void myFunction(std::string &fileName){
    ifstream file = ifstream(fileName);
    std::map<int,string> myMap;

    if(file.fail()){
        std::cerr<<"error opening file"<<std::endl;
        return;
    }
    std::cout<<"opening file"<<std::endl;

    std::string numberAsString;
    std::string word;

    //go through the file and add each number to word into a map for quick lookup
    while(!file.eof()){
        file >> numberAsString >> word;
        //convert string buffer into int
        int number = stoi(numberAsString);
        myMap[number] = word;
    }

    int iterator = 1;
    int counter = 0;
    //finds the last digit on each row of the pyramid and prints the corresponding string
    while(counter < myMap.size()){
        counter = counter + iterator;
        std::cout<<counter<<" "<<myMap[counter]<<" ";
        iterator++;
    }
    file.close();
}
