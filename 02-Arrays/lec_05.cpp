#include <bits/stdc++.h>
using namespace std;

// Two Sum

// Brute Force Approach
vector<int> brute(int arr[], int n, int target) {
    
    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            if (arr[i] + arr[k] == target) {
                return {arr[i], arr[k]};
            } 
        }
    }
}

// Better Approach
string better(int arr[], int n, int target) {
    unordered_map<int, int> mpp;
    
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        int req = target - x;

        if (mpp.find(req) != mpp.end()) return "YES"; // return {mpp[req], i};

        mpp[x] = i;
    }

    return "NO"; // return {-1, -1};
}

// Two pointer greedy approach
string two_pointer(int arr[], int n, int target) {

    sort(arr, arr + n);
    int left = arr[0];
    int right = arr[n-1];

    while (left < right) {
        
        if (arr[left] + arr[right] == target) {
            return "YES";
        }
        
        else if (arr[left] + arr[right] < target) {
            left++;
        }

        else {
            right--;
        }
    }

    return "NO";
    // cannot do this for returning indices, because you are sorting the array here.
}

int main() {

    return 0;
}