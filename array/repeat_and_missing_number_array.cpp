/*
There are certain problems which are asked in the interview to also check how you take care of overflows in your problem.
This is one of those problems.
Please take extra care to make sure that you are type-casting your ints to long properly and at all places. Try to verify if your solution works if number of elements is as large as 105

Food for thought :

Even though it might not be required in this problem, in some cases, you might be required to order the operations cleverly so that the numbers do not overflow.
For example, if you need to calculate n! / k! where n! is factorial(n), one approach is to calculate factorial(n), factorial(k) and then divide them.
Another approach is to only multiple numbers from k + 1 ... n to calculate the result.
Obviously approach 1 is more susceptible to overflows.
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int> repeatedNumber(const vector<int> &A) {
    vector<int> ans(2);
    ll n = A.size();
    ll adjustedSum = n*(n+1)/2;
    ll adjustedSq = n*(n+1)*(2*n+1)/6;
    for(int i = 0; i < n; i++) {
        adjustedSum -= (ll)A[i];
        adjustedSq -= (ll)A[i]*(ll)A[i];
    }
    ans[0] = ((adjustedSq/adjustedSum) - adjustedSum)/2;
    ans[1] = (adjustedSum + (adjustedSq/adjustedSum))/2;
    return ans;
}

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector<int> res = repeatedNumber(v);
    cout << res[0] << " " << res[1];
}