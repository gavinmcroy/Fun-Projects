#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int nearestValidPoint(int x, int y, vector<vector<int>> &points);

int main() {
//    vector<vector<int>> myData = {{1, 2},
//                                  {3, 1},
//                                  {2, 4},
//                                  {2, 3},
//                                  {4, 4}};
    //vector<vector<int>> myData = {{1,2}};
    vector<vector<int>> myData = {{1, 2},
                                  {2, 1},
                                  {1, 2},
                                  {1, 1},
                                  {1, 1},
                                  {1, 1},
                                  {1, 2},
                                  {2, 1},
                                  {2, 1},
                                  {2, 1},
                                  {2, 1}};
    std::cout << nearestValidPoint(1, 1, myData);
    return 0;
}

int nearestValidPoint(int x, int y, vector<vector<int>> &points) {
    int index = 0;
    int distance = std::numeric_limits<int>::max();
    bool validSolution = false;
    for (int i = 0; i < points.size(); i++) {
        if (points[i][0] == x || points[i][1] == y) {
            validSolution = true;
            /* Manhattan Distance */
            int tempDistance = abs(x - points[i][0]) + abs(y - points[i][1]);
            if (tempDistance < distance) {
                distance = tempDistance;
                index = i;
            }  /* This shouldn't return immediately*/
            else if (tempDistance == distance) {
                /* You want the smallest index, just because two distances equal
                 * does not mean thats the smallest distance possible */
                if (i < index) {
                    index = i;
                }
            }
        }
    }
    /* This means there is no valid solution */
    return validSolution ? index : -1;
}
