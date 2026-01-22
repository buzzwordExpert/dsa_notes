#include <bits/stdc++.h>
using namespace std;

// to traverse a matrix in a spiral manner
vector<int> spiralMatrix(vector<vector<int>> matrix) {
    int r = matrix.size();
    int c = matrix[0].size();

    int left = 0, right = c-1;
    int top = 0, bottom = r-1;

    vector<int> ans;

    while(top <= bottom && left <= right) {    
        for(int i = left; i <= right; i++) {
            ans.push_back(matrix[top][i]);
        }
        top++;
        
        for(int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom) {
            for(int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
        }
        bottom--;
        
        if (left <= right) {
            for(int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
        }
        left++;
    }
    return ans;
}

int main() {
    return 0;
}