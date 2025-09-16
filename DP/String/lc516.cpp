//516. Longest Palindromic Subsequence using LCS


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


//tabulation
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string r=s;
        reverse(r.begin(),r.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==r[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=0+ max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};