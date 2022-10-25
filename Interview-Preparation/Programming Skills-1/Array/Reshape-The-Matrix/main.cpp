#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c);

void printVector(std::vector<vector<int>> &vector1);

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<vector<int>> newVec = {{1, 2}};
    std::vector<vector<int>> test = matrixReshape(newVec, 1, 1);
    printVector(test);
    return 0;
}

vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
    /* condition for some value x 1 */
    std::vector<vector<int>> newVec;
    std::vector<int> forEase;

    /* What counts as a legal matrix. This is the problem area */
    if ((r * c != (mat[0].size() * mat.size()))) {
        return mat;
    }

    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            forEase.push_back(mat[i][j]);
        }
    }

    int tempCount = 0;
    for (int i = 0; i < r; i++) {
        std::vector<int> temp;
        for (int j = 0; j < c; j++) {
            temp.push_back(forEase[tempCount]);
            tempCount++;
        }
        newVec.push_back(temp);
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