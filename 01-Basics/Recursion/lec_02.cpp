#include<bits/stdc++.h>
using namespace std;


void f_0(int i, int n){
	if (i <= n) {
		cout << "tanishk\n";
		f_0(i+1,n);
	}
}

void f_1(int i, int n){
	if (i <= n){
		cout << i << endl;
		f_1(i+1,n);
	}
}

void f_2(int i, int n){

	if (i <= n){
		cout << n << endl;
		f_2(i, n-1);
	}
}

// Doing the same functions but with backtracking

void f_3(int i, int n){
	if (n >= i){
		f_3(i, n-1);
		cout << n << endl;
	}
}

void f_4(int i, int n){
	if (i <= n){
		f_4(i+1, n);
		cout << i << endl;
	}
}


int main(){
	
	f_0(1,3);
	cout << endl;

	f_1(1,5);
	cout << endl;

	f_2(1,3);
	cout << endl;

	f_3(1,3);
	cout << endl;
	
	f_4(1,3);
	cout << endl;

	return 0;
}
