#include <iostream>
#include <vector>

using namespace std;

int maximumWealth(vector<vector<int>> &accounts);

int main() {
    vector<vector<int>> accounts = {{1, 2, 3},
                                    {3, 2, 1}};
    vector<vector<int>> accounts1 = {{2, 8, 7},
                                     {7, 1, 3},
                                     {1, 9, 5}};
    vector<vector<int>> accounts2 = {{1, 5},
                                     {7, 3},
                                     {3, 5}};
    std::cout << maximumWealth(accounts2) << std::endl;
    std::cout << __cplusplus << std::endl;
    return 0;
}

int maximumWealth(vector<vector<int>> &accounts) {
    int max = 0;
    for (int i = 0; i < accounts.size(); i++) {
        int temp = 0;
        for (int j = 0; j < accounts[i].size(); j++) {
            temp += accounts[i][j];
        }
        if (temp > max) {
            max = temp;
        }
    }
    return max;
}