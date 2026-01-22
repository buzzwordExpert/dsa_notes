#include<bits/stdc++.h>
using namespace std;

// longest subarray with sum K
// BRUTE FORCE Approach O(n^2)
int brute(int arr[], int n, int target) {

    int len = INT_MIN;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += arr[j];
            if (sum == target) len = max(len, j-i + 1);
        }
    }
    return len;
}

// BETTER Approach using hashing 
int better(int arr[], int n, long long k) {
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        
        sum += arr[i];
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        long long rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        // this condition is to check if the current sum has already been done with
        // basically we don't want the hashmap to increase the index when we encounter a 0 or a -ve number
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
    // this is the optimal approach if the array has both -ve and +ve numbers
}

// Optimal (2 pointer) approach (doesn't work for -ve numbers and 0)
int optimal(int arr[], int n, int k) {
    int right = 0;
    int left = 0;
    int sum = arr[0];
    int len = 0;

    while(right < n) {

        while(left <= right && sum > k) {
            sum -= arr[left];
            left++;
        }
        
        if (sum == k) {
            len = max(len, right - left + 1);
        }

        right++;
        if (right < n) sum += arr[right];
    }

    return len;
}



int main() {

    return 0;
}
