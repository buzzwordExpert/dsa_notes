#include <bits/stdc++.h>
using namespace std;

// finding the longest consecutive sequence in an array


// for the brute force solution, sort the array and then keep a counter
// for how long a sequence is being maintained and then and update
// the longest (variable to return) with each increament in count
int brute(vector<int> nums, int n) {

    if (nums.size() == 0) return 0;

    sort(nums.begin(), nums.end());

    int n = nums.size();
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    for (int i = 0; i < n; i++) {

        if (nums[i] - 1 == lastSmaller) {
            cnt += 1;
            lastSmaller = nums[i];
        }
        else if (lastSmaller != nums[i]) {
            cnt = 1;
            lastSmaller = nums[i];
        }

        longest = max(longest, cnt);
    }

    return longest;

    // TC -> O(nlogn + n)
    // SC -> O(1)
} 

int optimal(vector<int> a, int n) {

    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;
    for (int i = 0; i < n; i++) st.insert(a[i]);

    for (auto it: st) {

        if (st.find(it - 1) == st.end()) {
            int cnt = 1;
            int x = it;
            
            while(st.find(x + 1) != st.end()) {
                x += 1;
                cnt += 1;
            }

            longest = max(longest, cnt);
        }
    }

    return longest;

    // TC -> O(n + 2n) = O(n) - only if collisions are not happening, otherwise use brute force
    // SC -> O(n)
}

int main() {
    return 0;
}