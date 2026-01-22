#include <bits/stdc++.h>
using namespace std;

// Set Matrix Zero

/*
    Think of the matrix as a chessboard. If you see a zero somewhere, you need to wipe out its whole row and column to zero. In brute force, the moment you find a zero, you immediately mark its entire row and column. But here’s the trap if you set them to zero immediately, we might mess up future checks because a newly placed zero could cause extra unwanted zeroing. To avoid that, we use a special marker value (like -1 or something that can’t exist in the input) to mark places where zeros should be placed later. Once the scanning is done, we do a second pass and replace all markers with 0.

    Traverse the entire matrix.
    If an element is zero:
        Mark all elements in its row (except already zero) as -1.
        Mark all elements in its column (except already zero) as -1.
    Once the full traversal is complete, replace all -1 with 0.

*/

void brute(vector<vector<int>> matrix) {

    int r = matrix.size();
    int c = matrix[0].size();

    // traverse for each cell
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {

            if (matrix[i][j] == 0) {

                for (int col = 0; col < c; col++) {
                    if (matrix[i][col] != 0) {
                        matrix[i][col] = -1;
                    }
                }

                for (int row = 0; row < r; row++) {
                    if (matrix[row][j] != 0) {
                        matrix[row][j] = -1;
                    }
                }
            }
        }
    }

    // replacing all -1 with 0
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (matrix[i][j] == -1) matrix[i][j] = 0;
        }
    }
    
    // TC -> O(m*n*(m+n))
    // SC -> O(1)
}

// better solution
void better(vector<vector<int>> matrix) {

    int r = matrix.size();
    int c = matrix[0].size();

    vector<int> row(r, 0);
    vector<int> col(c, 0);

    for (int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {

            if (matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    // setting cells to zero based on markers
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {

            if (row[i] == 1 || col[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }

    // TC -> O( 2*(m x n) )
    // SC -> O(m + n)
}

/*
    Instead of using separate arrays, we use the first row and first column of the matrix itself to store whether a row or column needs to be zeroed. We also store two flags:

    firstRowZero:Was the first row supposed to be all zero?
    firstColZero:Was the first column supposed to be all zero?

    Then:

    First pass: Mark zeros in the first row and column for any zero found in the rest of the matrix.
    Second pass: Use those markers to set rows and columns to zero.

    Finally, handle the first row and column separately based on the flags. This is super space-efficient because we’re reusing the input matrix itself to store markers.

    Check if the first row has any zero and store in a boolean flag.
    Check if the first column has any zero and store in a boolean flag.
    Traverse the rest of the matrix:
        If a cell is zero, mark its row in the first column and its column in the first row as zero.
    Traverse again (excluding first row and column), setting cells to zero if their row marker or column marker is zero.
    Finally, update the first row and first column based on the stored flags.

*/

void optimal(vector<vector<int>> matrix) {

    int r = matrix.size();
    int c = matrix[0].size();

    int col0 = 1;
    for (int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {

            if (matrix[i][j] == 0) {

                matrix[i][0] = 0;

                if (j!=0) matrix[0][j] = 0;
                else col0 = 0;
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (matrix[i][j] != 0) {

                if (matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
            }
        }
    }

    if (matrix[0][0] == 0) {
        for (int j = 0; j < c; j++) matrix[0][j] = 0;
    }

    if (col0 = 0) {
        for (int i = 0; i < c; i++) matrix[i][0] = 0;
    }
    // O(1) Space Complexity
}


int main() {
    return 0;
}