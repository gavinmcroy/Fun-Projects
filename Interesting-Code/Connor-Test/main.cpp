#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    double min = 10;
    int index = 0;
    std::vector<double> data = {4.56 , 4.99, 4.15,4.89 };
    for(int i =0; i < data.size(); i++){
        double temp = std::pow((data[i]-5),2);
        if(temp < min){
            min = temp;
            index = i;
        }
    }
    std::cout<<index<<std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
