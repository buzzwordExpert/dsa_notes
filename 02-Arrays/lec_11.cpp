#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> a, int n) {
    
    int index = -1;

    for (int i = n - 2; i >= 0; i--) {

        if (a[i] < a[i + 1]) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        reverse(a.begin(), a.end());
        return a;
    }
    for (int i = n - 1; i > index; i--) {
        if (a[i] > a[index]) {
            swap(a[i], a[index]);
            break;
        }
    }

    reverse(a.begin() + index + 1, a.end());
    return a;
}

int main() {

    return 0;
}