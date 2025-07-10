#include<bits/stdc++.h>
using namespace std;
int f(int ind,int sum,int arr[],vector<int>& ds,int n,int k){
    if(ind==n){
        if(sum==k){
            return 1;
        }
        else return 0;
    }
    ds.push_back(arr[ind]);
    sum+=arr[ind];
    int left=f(ind+1,sum,arr,ds,n,k);
    ds.pop_back();
    sum-=arr[ind];
    int right=f(ind+1,sum,arr,ds,n,k);
    return left + right;
}
int main(){
    int arr[3]={1,2,1};
    vector<int> ds;
    int k=2;
    cout<<"The number of subsequence whose sum is 2 is "<<f(0,0,arr,ds,3,k);
}