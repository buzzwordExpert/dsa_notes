#include <bits/stdc++.h>
using namespace std;

// to find the element not present in the array of numbers from 1 to N
int not_present_elmt(int arr[], int n) {

    int sum = n * (n + 1) / 2;
    for (int i = 0; i < n; i++) {
        sum = sum - arr[i];
    }
    return sum;
}
// can use XOR approach as well, will try that after learning bit manipulation

// to count the maximum amount of ones occurring consecutively
int max_consecutive_ones(int arr[], int n) {

    int ans = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        
        if (arr[i] == 1) cnt++;

        else {
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    return ans;
}


int main() {

    int arr[5] = {1,1,3,1,5};
    int ans = max_consecutive_ones(arr, sizeof(arr));
    cout << ans;
    return 0;
}