#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void f()
{
	if (cnt == 5) return;
	cout << cnt;
	cnt += 1;
	f();
}

int main() 
{
	
	f();
	return 0;
}
