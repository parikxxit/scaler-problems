/*
Given an unsorted integer array, A of size N. Find the first missing positive integer.

Note: Your algorithm should run in O(n) time and use constant space
*/
#include<bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> &A) {
    int n = A.size();
    for(int i=0;i<n;i++){
            if(A[i]<=n && A[i]>0 && A[A[i]-1]!=A[i]){
                int temp = A[A[i]-1];
                A[A[i]-1] = A[i];
                A[i] = temp;
                i--;
            }
        }
        
        for(int i=0;i<n;i++){
            if(A[i]!=i+1) return i+1;
        }
        
        return n+1;
}

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << firstMissingPositive(v);
}