#include<bits/stdc++.h>
using namespace std;

// reversing an array with recursion

void f(int i, int arr[], int n){
	if (i >= n/2) return;
	swap(arr[i], arr[n-i-1]);
	f(i+1,arr, n);
}

// checking for a palindrome string
//
bool f_1(int i, string &s){
	
	if( i >= s.size()/2 ) return true;
	if(s[i] != s[s.size() - i - 1]) return false;
	return f(i+1, s);
}


int main() {

	int n = 5;
	int arr[n] = {1,2,3,4,5};

	f(0, arr, n);
	for(int i = 0;i < n; i++) cout << arr[i] << " ";
	return 0;
}
