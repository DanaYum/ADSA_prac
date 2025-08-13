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
// } TC-> O(n) SC-> O(n)+O(n)



// Fibonacci using tabulation
// int main(){
//     int n;
//     cin>>n;
//     vector<int> dp(n+1);
//     dp[0]=0;
//     dp[1]=1;
//     for(int i=2;i<=n;i++){
//         dp[i]=dp[i-1]+dp[i-2];
//     }
//     cout<<dp[n];
// } TC-> O(n) SC-> O(n)


// space optimization
int main(){
    int n;
    cin>>n;
    int prev2=0,prev1=1;
    for(int i=2;i<=n;i++){
        int curr=prev1 + prev2;
        prev2 = prev1;
        prev1=curr;
    }
    cout<<prev1;
}
