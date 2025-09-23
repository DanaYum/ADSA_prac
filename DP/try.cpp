#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int dp[n];
    dp[0]=arr[0];
    for(int i=0;i<n;i++){
        int take=arr[i];
        if(i>1) take += dp[i-2];
        else if(i==1) take += 0; // If only two houses, can't rob the first and second together 
        if(i<1){
            int notTake=0;
        }
        int notTake=0 + dp[i-1];
        dp[i]=max(take,notTake);
    }
    cout<<dp[n-1];
}