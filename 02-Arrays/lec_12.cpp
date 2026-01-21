#include <bits/stdc++.h>
using namespace std;

// brute solution is just two nested for loops O(n^2)

// optimal solution
// the last element of the array will be the leader by default
// in a variable the max element and then iterate from the last to first element
// if the current num in the iteration is greater than the max element till now 
// then that will be a leader

vector<int> leaderElements(vector<int> a, int n) {

    vector<int> ans;
    int maximum = INT_MIN;

    for (int i = n-1; i >= 0; i--) {

        if (a[i] > maximum) {
            ans.push_back(a[i]);
            maximum = a[i];
        }
    }

    // you can sort before returning if that is required

    return ans;
}

int main() {
    return 0;
}