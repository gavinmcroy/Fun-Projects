#include<iostream>

#include<stdio.h>
#include <limits.h>
#include <map>
#include <vector>
#include<conio.h>
#include<iostream>

using namespace std;
int c = 0, cost = 999;
int graph[4][4] = {{0,  10, 15, 20},
                   {10, 0,  35, 25},
                   {15, 35, 0,  30},
                   {20, 25, 30, 0}
};

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void copy_array(const int *a, int n) {
    int i, sum = 0;
    for (i = 0; i <= n; i++) {
        sum += graph[a[i % 4]][a[(i + 1) % 4]];
    }
    if (cost > sum) {
        cost = sum;
    }
}

void permute(int *a, int i, int n) {
    int j;
    if (i == n) {
        copy_array(a, n);
    } else {
        for (j = i; j <= n; j++) {
            swap((a + i), (a + j));
            permute(a, i + 1, n);
            swap((a + i), (a + j));
        }
    }
}

int main() {
    int i, j;
    int a[] = {0, 1, 2, 3};
    permute(a, 0, 3);
    cout << "minimum cost:" << cost << endl;
    //getch();
}


void findMinRoute(vector<vector<int> > tsp) {
    int sum = 0;
    int counter = 0;
    int j = 0, i = 0;
    int min = INT_MAX;
    map<int, int> visitedRouteList;

    // Starting from the 0th indexed
    // city i.e., the first city
    visitedRouteList[0] = 1;
    int route[tsp.size()];
    // Traverse the adjacency
    // matrix tsp[][]
    while (i < tsp.size() && j < tsp[i].size()) {
        // Corner of the Matrix
        if (counter >= tsp[i].size() - 1) {
            break;
        }
        // If this path is unvisited then
        // and if the cost is less then
        // update the cost
        if (j != i && (visitedRouteList[j] == 0)) {
            if (tsp[i][j] < min) {
                min = tsp[i][j];
                route[counter] = j + 1;
            }
        }
        j++;

        // Check all paths from the
        // ith indexed city
        if (j == tsp[i].size()) {
            sum += min;
            min = INT_MAX;
            visitedRouteList[route[counter] - 1] = 1;
            j = 0;
            i = route[counter] - 1;
            counter++;
        }
    }

    // Update the ending city in array
    // from city which was last visited
    i = route[counter - 1] - 1;

    for (j = 0; j < tsp.size(); j++) {

        if ((i != j) && tsp[i][j] < min) {
            min = tsp[i][j];
            route[counter] = j + 1;
        }
    }
    sum += min;

    // Started from the node where
    // we finished as well.
    cout << ("Minimum Cost is : ");
    cout << (sum);
}