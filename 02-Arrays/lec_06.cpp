#include <bits/stdc++.h>
using namespace std;

// in brute force, just use merge sort
// TC - O(nlogn)
// SC - O(n)

// for a better solution, keep a counter for 0, 1 and 2. then overwrite the original array
// with the counter data
// TC - O(2N)
// SC - O(1)
void better(vector<int> nums) {
    
    int cnt_0 = 0, cnt_1 = 0, cnt_2 = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) cnt_0++;
        else if (nums[i] == 1) cnt_1++;
        else cnt_2++;
    }

    int index = 0;

    while(cnt_0--) {
        nums[index++] = 0;
    }
    while(cnt_1--) {
        nums[index++] = 1;
    }
    while(cnt_2--) {
        nums[index--] = 2;
    }
}

// optimal approach is using the dutch national flag algorithm
/*
    This approach is a direct implementation of the Dutch National Flag algorithm.

    We divide the array into three partitions using three pointers – low, mid, and high.

    From 0 to low-1, we’ll keep only 0s
    From low to mid-1, only 1s
    From high+1 to n-1, only 2

    The range from mid to high is the unsorted zone we’re scanning and fixing. At each step:

    If arr[mid] == 0, it belongs to the left section → swap with low, move both low and mid.
    If arr[mid] == 1, it’s already in the middle section → just move mid.
    If arr[mid] == 2, it belongs to the right section → swap with high, only move high.

    When you swap with high, you don’t move mid because the incoming value might still be 0 or 2 which needs processing.This ensures we sort the array in one single pass without using extra space.

    Start with three pointers at the beginning, middle, and end of the array.
    Iterate while the middle pointer is less than or equal to the end pointer.
    If the current element belongs to the front section:
        Swap it with the element at the front boundary.
        Move both front and middle boundaries forward.
    If the current element belongs to the middle section:
        Move the middle boundary forward.
    If the current element belongs to the end section:
        Swap it with the element at the end boundary.
        Move the end boundary backward.
    Repeat until all elements are in their correct zones.

    TC - O(N)
    SC - O(1)
*/

void optimal(vector<int> nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while(mid <= high) {
        
        if (nums[mid] == 0) {
            swap(nums[mid], nums[low]);
            mid++;
            low++;
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {

    return 0;
}