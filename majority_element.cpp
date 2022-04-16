/*
Given an array of size N, find the majority element. The majority element is the element that appears more than floor(n/2) times.
You may assume that the array is non-empty and the majority element always exists in the array.
*/
#include<bits/stdc++.h>
using namespace std;
int majorityElement(const vector<int> &A) {
    int ptr = 0;
    int tn = 1;
    int cn = A[0];
    for(int i = 1; i < A.size(); i++) {
        if(tn == 0) {
            tn = 1;
            cn = A[i];
        } else if(cn == A[i]) {
            tn++;
        } else {
            tn--;
        }
    }
    int mc = 0;
    for(int i = 0; i < A.size(); i++) {
        if(cn == A[i]) mc++;
    }
    if(mc*2 > A.size()) {
        return cn;
    }
    return -1;
}
int main() {
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << majorityElement(v);
}