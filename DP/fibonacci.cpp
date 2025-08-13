#include<bits/stdc++.h>
using namespace std;
// Fibonacci using memoization
// int fib(int n,vector<int>& dp){
//     if(n<=1) return n;
//     if(dp[n]!=-1) return dp[n];
//     return dp[n] = fib(n-1,dp) + fib(n-2,dp);
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int> dp(n+1,-1);
//     cout<<fib(n,dp);
// }
// Fibonacci using tabulation
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n];
}
