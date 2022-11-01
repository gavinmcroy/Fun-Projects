#include <iostream>
#include <vector>

using namespace std;

bool checkStraightLine(vector<vector<int>> &coordinates);

int main() {
    std::vector<vector<int>> coord = {{1, 2},
                                      {2, 3},
                                      {3, 4},
                                      {4, 5},
                                      {5, 6},
                                      {6, 7}};
    std::cout<<checkStraightLine(coord);
    return 0;
}

/* We can always assume coord will contain 2 elements */
/* As long as the increment from the first element is constant, then it's a straight line */
bool checkStraightLine(vector<vector<int>> &coordinates) {
    /* this specifies how much the x and y should increase for each iteration*/
    std::pair<int, int> myPair(abs(coordinates[0][0] - coordinates[1][0]), abs(coordinates[0][1] - coordinates[1][1]));
    std::cout<<coordinates.size()<<endl;
    for (int i = 0; i < coordinates.size() - 1; i++) {
        std::pair<int, int> tempPair(abs(coordinates[i][0] - coordinates[i+1][0]),
                                     abs(coordinates[i][1] - coordinates[i + 1][1]));
        if(tempPair != myPair){
            return false;
        }
    }
    return true;
}
