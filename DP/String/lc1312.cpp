//1312. Minimum Insertion Steps to Make a String Palindrome
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lps(string str) {
        int n = str.size();
        string r = str;
        reverse(r.begin(), r.end());

        // DP table (n+1) x (n+1)
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        // Fill DP
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(str[i-1] == r[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][n]; // LPS length
    }

    int minInsertions(string s) {
        int m = s.size();
        return m - lps(s);
    }
};
