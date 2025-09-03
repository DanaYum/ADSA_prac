#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp, int n, int m) {
        if (j < 0 || j >= m) return 1e9; // invalid column
        if (i == 0) return matrix[i][j]; // base case
        if (dp[i][j] != -1) return dp[i][j];

        int straight = matrix[i][j] + f(i - 1, j, matrix, dp, n, m);
        int ldiag    = matrix[i][j] + f(i - 1, j - 1, matrix, dp, n, m);
        int rdiag    = matrix[i][j] + f(i - 1, j + 1, matrix, dp, n, m);

        return dp[i][j] = min({straight, ldiag, rdiag});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = 1e9;
        for (int k = 0; k < m; k++) {
            ans = min(ans, f(n - 1, k, matrix, dp, n, m));
        }
        return ans;
    }
};


// Tabulation 
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            dp[0][j]=matrix[0][j];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int straight=matrix[i][j] + dp[i-1][j];
                int ld= (j>0)? matrix[i][j] + dp[i-1][j-1] : 1e9;
                int rd= (j<m-1)? matrix[i][j] + dp[i-1][j+1] : 1e9;

                dp[i][j]=min({straight,ld,rd});
            }
        }
        int ans = 1e9;
        for (int j = 0; j < m; j++) {
            ans = min(ans, dp[n - 1][j]);
        }

        return ans;

    }
};