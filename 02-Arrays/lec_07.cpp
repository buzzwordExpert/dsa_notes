#include <bits/stdc++.h>
using namespace std;

// finding majority element ( > N/2 times)
// brute is O(N^2)
// better is just hashing which TC -> O(nlogn + n) , SC -> O(n)

// Moore's Voting Algorithm
// most optimal approach
int majorityElement(vector<int> v) {
    int cnt = 0;
    int elmt;
    int len = v.size();

    for (int i = 0; i < len; i++) {
        
        if (cnt == 0) {
            cnt = 1;
            elmt = v[i];
        }

        else if (v[i] == elmt) cnt++;

        else cnt--;
    }

    // till this loop you can say that the elmt is in majority
    // but you will have to verify if it is > N/2 majority

    int cnt1 = 0;
    for (int i = 0; i < len; i++) {
        if (v[i] == elmt) cnt1++;
    }

    if (cnt1 > (len / 2)) return elmt;

    return -1;
    
}
int main() {
    return 0;
}