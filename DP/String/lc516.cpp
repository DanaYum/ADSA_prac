//516. Longest Palindromic Subsequence using LCS code


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(int ind1,int ind2, string& s, string& r,vector<vector<int>>& dp){
        if(ind1<0 || ind2<0) return 0;
        if(dp[ind1][ind2]!= -1) return dp[ind1][ind2];
        if(s[ind1]==r[ind2]){
            return 1 + f(ind1-1,ind2-1,s,r,dp);
        }
        return dp[ind1][ind2]=0 + max(f(ind1-1,ind2,s,r,dp),f(ind1,ind2-1,s,r,dp));
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string r=s;
        reverse(r.begin(),r.end());
        int m=r.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,r,dp);

    }
};