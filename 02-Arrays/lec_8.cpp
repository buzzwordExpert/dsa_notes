#include <bits/stdc++.h>
using namespace std;

// maximum subarray sum
// Kadene's Algorithm

int maxSubArray(vector<int>& nums) {
    // maximum sum
    long long maxi = LLONG_MIN; 
        
    // current sum of subarray
    long long sum = 0; 
        
    // Iterate through the array
    for (int i = 0; i < nums.size(); i++) {
        
        // Add current element to the sum
        sum += nums[i]; 
            
        // Update maxi if current sum is greater
        if (sum > maxi) {
            maxi = sum; 
        }
            
        // Reset sum to 0 if it becomes negative
        if (sum < 0) {
            sum = 0; 
        } 
    }
        
        // Return the maximum subarray sum found
        return maxi;
    
    // TC -> O(n)
    // SC -> O(1)
}

// for printing the subarray itself with the maximum sum
int maxSubArray(vector<int>& nums) {
        
    long long maxi = LLONG_MIN; 
    long long sum = 0;
    int start = 0; 
    int ansStart = -1, ansEnd = -1; 
    
    for (int i = 0; i < nums.size(); i++) {
    
        if (sum == 0) {
            start = i;
        }
        
        sum += nums[i]; 
        
        /* Update maxi and subarray indice
        s if current sum is greater*/
        if (sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        
        // Reset sum to 0 if it becomes negative
        if (sum < 0) {
            sum = 0;
        }
    }
    
    // Printing the subarray
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << nums[i] << " ";
    }
    cout << "]" << endl;
    
    // Return the maximum subarray sum found
    return maxi;
}

int main() {
    return 0;
}