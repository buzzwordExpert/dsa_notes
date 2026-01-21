#include<bits/stdc++.h>
using namespace std;

// rearranging array with alternating signs
vector<int> brute(vector<int> a, int n) {
    
    // store the positive and negative numbers seperately and then make another
    // array with desired configuration
    vector<int> positive;
    vector<int> negative;

    for (int i = 0; i < n; i++) {
        if (a[i] > 0) positive.push_back(a[i]);
        else negative.push_back(a[i]);
    }

    // placing positives at even indices and negatives at odd indices
    for (int i = 0; i < n / 2; i++) {
        a[2 * i] = positive[i];
        a[2 * i + 1] = negative[i];
    }

    return a;

    // TC -> O(n + n/2)
    // SC -> O(n)
}
// best approach if the number of positives and negatives is not equal

// optimal approach (only if the number of positives and negatives are equal)
vector<int> optimal(vector<int> a, int n) {
    
    vector<int> ans(n, 0);

    int posIndex = 0, negIndex = 1;

    for (int i = 0; i < n; i++) {

        if (a[i] < 0) {
            ans[negIndex] = a[i];
            negIndex += 2;
        }

        else {
            ans[posIndex] = a[i];
            posIndex += 2;
        }
    }

    // TC -> O(n)
    // SC -> O(n)

}

// case when positive and negative numbers are not equal
vector<int> alternateNumber(vector<int> a, int n) {

    vector<int> pos, neg;

    for (int i = 0; i < n; i++) {

        if (a[i] > 0) pos.push_back(a[i]);
        else neg.push_back(a[i]);
    }

    if (pos.size() > neg.size()) {

        for (int i = 0; i < neg.size(); i++) {
            a[2 * i] = pos[i];
            a[2 * i + 1] = neg[i];
        }
        int index = neg.size() * 2;
        for (int i = index; i < pos.size(); i++) {
            a[index] = pos[i];
            index++;
        }
    }
    else {

        for (int i = 0; i < pos.size(); i++) {
            a[2 * i] = pos[i];
            a[2 * i + 1] = neg[i];
        }

        int index = pos.size() * 2;
        for (int i = index; i < neg.size(); i++) {
            a[index] = neg[i];
            index++;
        }
    }

    // TC -> O(2n)
    // SC -> O(n)
}

int main() {

    return 0;
}