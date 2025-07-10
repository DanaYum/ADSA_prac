#include <bits/stdc++.h>
using namespace std;
// This code prints all subsequences of a given array.
void f1(int ind, vector<int>& ds, int arr[], int n) {
    if (ind == n) {
        for (int i = 0; i < ds.size(); ++i) {
            cout << ds[i]<<" ";
        }
        if (ds.size() == 0) {
            cout << "{}"; // Print empty set if no elements are selected
        }
        cout << endl;
        return;
    }
    ds.push_back(arr[ind]);
    f1(ind + 1, ds, arr, n);
    ds.pop_back();
    f1(ind + 1, ds, arr, n);
}
// This code prints all subsequences whose sum is equal to k.
void f2(int ind,int sum,int arr[],vector<int>& ds,int n,int k){
    if(ind == n){
        if(sum==k){
            for(auto it: ds){
                cout<<it<<" ";
            }
            cout<<endl;
        }

        return;
    }
    ds.push_back(arr[ind]);
    sum+=arr[ind];
    f2(ind+1,sum,arr,ds,n,k);
    ds.pop_back();
    sum-=arr[ind];
    f2(ind+1,sum,arr,ds,n,k);

}
// This code counts the number of subsequences whose sum is equal to k.
// It uses a recursive function to explore all possible subsequences and checks their sums.
int f3(int ind,int sum,int arr[],vector<int>& ds,int n,int k){
    if(ind==n){
        if(sum==k){
            return 1;
        }
        else return 0;
    }
    ds.push_back(arr[ind]);
    sum+=arr[ind];
    int left=f3(ind+1,sum,arr,ds,n,k);
    ds.pop_back();
    sum-=arr[ind];
    int right=f3(ind+1,sum,arr,ds,n,k);
    return left + right;
}

