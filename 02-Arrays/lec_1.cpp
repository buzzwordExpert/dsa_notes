#include<bits/stdc++.h>
using namespace std;

int largest_element(int arr[], int n) {
	
	int largest = INT_MIN;

	for (int i = 0; i < n; i++) {
		largest = max(largest, arr[i]);
	}
	return largest;
}

int second_largest_element(int arr[], int n) {

	int ans = INT_MIN;

	for (int i = 0; i < n; i++) {
		ans = max(ans, arr[i]);
	}

	int temp = INT_MIN;

	for (int i = 0; i < n; i++) {
		
		if ((arr[i] < ans) && (arr[i] > temp) temp = arr[i];
	}

	ans = temp;
	return ans;
}

bool is_array_sorted(int arr[], int n) {
	
	for (int i = 1; i < n; i++) {
		
		if (arr[i-1] <= arr[i]) continue;
		
		else {
		return false;
		}
	}
	return true;
}


// Two-Pointer approach to remove duplicates in-place from a sorted array
void rem_dup(int arr[]. int n) {
	
	int i = 0;

	for (int j = 1; j < n; j++) {
		if (arr[i] != arr[j]) {
			arr[i+1] = arr[j];
			i++;
		}
	}
}


int main() {

	return 0;
}
