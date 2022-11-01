#include <iostream>
#include <vector>
#include <limits>

using namespace std;

double average(vector<int> &salary);


int main() {
    std::vector<int> myVec = {1000, 2000, 3000};
    std::cout << average(myVec) << std::endl;
}


double average(vector<int> &salary) {
    int min = std::numeric_limits<int>::max();
    int max = std::numeric_limits<int>::min();
    double average = 0;
    for (int i = 0; i < salary.size(); i++) {
        if (salary[i] > max) {
            max = salary[i];
        }
        if (salary[i] < min) {
            min = salary[i];
        }
        average += salary[i];
    }
    /* salary.size() - 2 because we are excluding min and max */
    average = (average - min - max) / (salary.size() - 2);
    return average;
}
