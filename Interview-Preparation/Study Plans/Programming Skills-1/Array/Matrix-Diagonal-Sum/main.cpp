#include <iostream>
#include <vector>

using namespace std;

int diagonalSum(vector<vector<int>> &mat);

int main() {
    vector<vector<int>> matrix = {{1, 1, 1, 1},
                                  {1, 1, 1, 1},
                                  {1, 1, 1, 1},
                                  {1, 1, 1, 1}};
    std::cout << diagonalSum(matrix);

    return 0;
}

int diagonalSum(vector<vector<int>> &mat) {
    int sum = 0;
    int farRight = mat.size() - 1;
    for (int i = 0; i < mat.size(); i++) {
        /* secondary diagonal (top right to bottom left)*/
        if (i != farRight) {
            sum += mat[i][farRight];
        }
        /* primary diagonal */
        sum += mat[i][i];
        farRight--;
    }
    return sum;
}


//        for(int j = 0; j < mat[i].size(); j++){
//            //primary diagonal
//            if(i==j){
//                sum+=mat[i][j];
//            }
//        }

/* Its square so the elements in the column is the same as rows */
//int farRight = mat.size()-1;
//    for(int i = 0; i < mat.size(); i++){
//        if(i!=farRight){
//            sum+=mat[i][farRight];
//        }
//        farRight--;
//    }