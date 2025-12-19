#include<bits/stdc++.h>
using namespace std;

// using recursion to print fibonacci sequence

void fillFibonacci(int fib[], int n) {
    if (n <= 0) return;

    // initialize base values ONCE
    fib[0] = 0;
    if (n > 1)
        fib[1] = 1;

    // recursive filling from index 2 onward
    if (n <= 2) return;

    fillFibonacci(fib, n - 1);
    fib[n - 1] = fib[n - 2] + fib[n - 3];
}

int main() {
    int n = 6;
    int fib[n];

    fillFibonacci(fib, n);

    for (int i = 0; i < n; i++)
        cout << fib[i] << " ";
}


