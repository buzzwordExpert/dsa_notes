#include<bits/stdc++.h>
using namespace std;


// Parametised Recursion (print the final value)
void f_0(int n, int sum = 0){
	if ( n > 0 ){
		return f_0(n-1,sum + n);
	}
	cout << sum << endl;
}

// Functioncal recursion (returns the final value)
int f_1(int n){
	if (n == 0){
		return 0;
	}
	return n + f_1(n-1);
}




int main(){
	f_0(5);
	cout << endl;

	cout << f_1(6) << endl;

	return 0;
}
