#include <bits/stdc++.h>
using namespace std;

// to left rotate the array by one place
void lrotate_one(int arr[], int n) {
	int temp = arr[0];

	for (int i = 1; i < n; i++) {
		arr[i-1] = arr[i];
	}
	arr[n-1] = temp;
}

// to left rotate the array by some D places
void lrotate_byD(vector<int> &arr, int n, int d)
{
    d = d % n;
    vector<int> temp(d);
	
    // storiing temp elements
    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[i];
    }

    // shifting
    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }

    // placing temp temp elements
    for (int i = n - d; i < n; i++)
    {
        arr[i] = temp[i - (n - d)];
    }
}
// TC - O(n) = n + d
// SC - O(d)

// Or better way(reverse it)

void usingReverse(int arr[], int n, int d)
{
    reverse(arr, arr + d);
    reverse(arr + d, arr + n);
    reverse(arr, arr + n);
}
// TC - O(2n)
// SC - O(1)

void zero_to_end(int arr[], int  n) {
	
	int j = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) {
			j = i;
			break;
		}
	}
	
	if (j != -1) {
		for (int i = j+1; i < n; i++){
			if (arr[i] != 0) {
				swap(arr[i],arr[j]);
				j++;
			}
		}

	}
}

// Two pointer approach to make an Union of two sorted arrays
void union_arr(int arr1[], int arr2[], vector<int> UnionArr, int n1, int n2){

	int i = 0;
	int j = 0;
	
	while( i < n1 && j < n2) {
		if (arr1[i] <= arr2[j]) {
			if (UnionArr.size() == 0 || arr1[i] != UnionArr.back()) {
				UnionArr.push_back(arr1[i]);
			}
			i++;
		}
		else {
			if (UnionArr.size() == 0 || UnionArr.back() != arr2[j]) {
				UnionArr.push_back(arr2[j]);
			}
			j++;
		}

	}

	while (j < n2) {
		if (UnionArr.size() == 0 || UnionArr.back() != arr2[j]) {
				UnionArr.push_back(arr2[j]);
		}
			j++;
	}

	while (i < n1) {
		if (UnionArr.size() == 0 || arr1[i] != UnionArr.back()) {
				UnionArr.push_back(arr1[i]);
		}
		i++;
	}
}
// TC - O(n1 + n2)
// SC - O(n1 + n2) in the sense that we us the arrays to solve this
// SC - O(1) if talking in the sense that we aren't using anything extra for solving the problem
// with the already existing data


// Intersection of two sorted arrays
void intersection_of_2_sorted_arr(int arr1[], int arr2[], vector<int> ans, int n1, int n2) {

	int i = 0;
	int j = 0;
	while (i<n1 && j<n2) {
		
		if (arr1[i] < arr2[j]) i++;

		else if (arr2[j] < arr1[i]) j++;

		else {
			ans.push_back(arr1[i]);
			i++;
			j++;
		}
	}

}

int main() {
	
	return 0;
}
