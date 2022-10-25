#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c);

void printVector(std::vector<vector<int>> &vector1);

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<vector<int>> newVec = {{1,2,3,4}};
    printVector(newVec);
    return 0;
}

vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
    /* condition for some value x 1 */
    std::vector<vector<int>> newVec;
    if (r == 1) {
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                newVec[0].push_back(mat[i][j]);
            }
        }
    }
    return newVec;
}

void printVector(std::vector<vector<int>> &vector1) {
    for (int i = 0; i < vector1.size(); i++) {
        for (int j = 0; j < vector1[i].size(); j++) {
            std::cout << vector1[i][j] << " ";
        }
        cout << endl;
    }
}