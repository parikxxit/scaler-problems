/*
Rain Water Trapped
Given a vector A of non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
*/

#include<bits/stdc++.h>
using namespace std;
int trap(const vector<int> &A) {
    int m = INT_MIN;
    int mi = 0;
    int ans = 0;
    for(int i = 0; i < A.size(); i++) {
        if(m < A[i]) {
            m = A[i];
            mi = i;
        }
    }
    int ml = INT_MIN;
    for(int i = 0; i < mi; i++) {
        ml = max(ml, A[i]);
        ans += (min(ml, m)-A[i]);
    }
    ml = INT_MIN;
    for(int i = A.size() -1; i > mi; i--) {
        ml = max(ml,A[i]);
        ans += (min(ml,m)-A[i]);
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << trap(v);
}