#include <bits/stdc++.h>
using namespace std;

// matrix rotation by 90deg for a square matrix

void optimalCauseIcan(vector<vector<int>> matrix) {

    int n = matrix.size();

    // transpose the matrix
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // reverse every columns
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }

    // TC -> O(n/2*n/2 + n*n/2)
    // SC -> O(1)
}


int main() {
    return 0;
}