#include <bits/stdc++.h>
using namespace std;

// Number of sub arrays with sum K
// can be solved with the presum logic covered before

int optimal(vector<int> arr, int k) {
    
    unordered_map<int,int> mpp;
    mpp[0] = 1;
    int preSum = 0, cnt = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        preSum += arr[i];
        int remove = preSum - k;
        cnt += mpp[remove];
        mpp[preSum] += 1;
    }

    return cnt;
}

int main() {
    return 0;
}