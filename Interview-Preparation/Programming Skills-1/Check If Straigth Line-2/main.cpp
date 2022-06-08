#include <iostream>
#include <vector>

using namespace std;

bool checkStraightLine(vector<vector<int>> &coordinates);

int main() {
//    std::vector<vector<int>> coord = {{2, 0},
//                                      {2, -20},
//                                      {2, 0},
//                                      {2, 0}};
    //std::vector<vector<int>> coord = {{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}};
//    std::vector<vector<int>> coord = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
    std::vector<vector<int>> coord = {{1, -8},
                                      {2, -3},
                                      {1, 2}};
    std::cout << checkStraightLine(coord);
    return 0;
}

/* We can always assume coord will contain 2 elements */
/* As long as the increment from the first element is constant, then it's a straight line */
bool checkStraightLine(vector<vector<int>> &coordinates) {
    /* We need to calculate slope between each point*/
    /* this specifies how much the x and y should increase for each iteration*/
    /* (y2 -y1 / x2 - x1) */

    /* x is constant, y is changing */
    if (coordinates[1][0] - coordinates[0][0] == 0) {
        int x = coordinates[0][0];
        for (int i = 0; i < coordinates.size(); i++) {
            /* x changes therefore it's not a straight line */
            if (coordinates[i][0] != x) {
                return false;
            }
        }
    } /* x is changing, y is constant */
    else if (coordinates[1][1] - coordinates[0][1] == 0) {
        int y = coordinates[0][1];
        for (int i = 0; i < coordinates.size(); i++) {
            if (coordinates[i][1] != y) {
                return false;
            }
        }
    } else {
        const double EPSILON = .001;
        const double SLOPE =
                (coordinates[1][1] - coordinates[0][1]) / ((double) coordinates[1][0] - coordinates[0][0]);
        for (int i = 0; i < coordinates.size() - 1; i++) {
            double tempSlope =
                    (coordinates[i + 1][1] - coordinates[i][1]) / ((double) coordinates[i + 1][0] - coordinates[i][0]);
            if (abs(SLOPE - tempSlope) > EPSILON) {
                return false;
            }
        }
    }
    return true;
}
