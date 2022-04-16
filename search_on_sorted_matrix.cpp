/*
Given a matrix of integers A of size N x M and an integer B.
In the given matrix every row and column is sorted in increasing order. Find and return the position of B in the matrix in the given form:
If A[i][j] = B then return (i * 1009 + j)
If B is not present return -1.

Note 1: Rows are numbered from top to bottom and columns are numbered from left to right.
Note 2: If there are multiple B in A then return the smallest value of i*1009 +j such that A[i][j]=B.
*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int> > &A, int B) {
    int row = A.size()-1;
    int col = A[0].size()-1;
    int sr = 0, sc = col;
    while (sr <= row && sc >= 0) {
        cout << sr << " " << sc << endl;
        if(A[sr][sc] == B) return (sr + sc*1009);
        else if(A[sr][sc] < B) sr++; 
        else sc--;
    }
    return -1;
}

int main() {
    int n,m; cin >> n >> m;
    vector<vector<int>>v(n, vector<int>(m,0));
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) cin >> v[i][j];
    int x; cin >> x;
    cout << solve(v,x);
}