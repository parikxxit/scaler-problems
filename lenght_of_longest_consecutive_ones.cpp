/*
Given a binary string A. It is allowed to do at most one swap between any 0 and 1. Find and return the length of the longest consecutive 1’s that can be achieved.
*/

#include<bits/stdc++.h>
using namespace std;

int solve(string A) {
    int len = A.size();int ans = 0;
    vector<int> modPrefixSum(len);
    vector<int> modSuffixSum(len);
    modPrefixSum[0] = A[0]-'0';
    modSuffixSum[len-1] = A[len-1] - '0';
    int oneCnt = modPrefixSum[0];
    for(int i = 1; i < len; i++) {
        if(A[i] == '1') {
            modPrefixSum[i] = modPrefixSum[i-1] + (A[i] - '0');
            oneCnt++;
        } else if(A[i] == '0') {
            modPrefixSum[i] = 0;
        }
    }
    if(oneCnt == len) return oneCnt;
    for(int i = len - 2; i >= 0; i--) {
        if(A[i] == '1') {
            modSuffixSum[i] = modSuffixSum[i+1] + (A[i] - '0');
        } else {
            modSuffixSum[i] = 0;
        }
    }
    for(int i = 0; i < len; i++) {
        if(A[i] == '0') {
            int lSum = 0, rSum = 0;
            if(i != 0) {
                lSum = modPrefixSum[i-1];
            }
            if(i != len -1) {
                rSum = modSuffixSum[i+1];
            }
            if(lSum + rSum == oneCnt) ans = max(ans, lSum+rSum);
            else ans = max(ans, lSum + rSum + 1);
        }
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << solve(s);
}